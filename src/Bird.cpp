#include "Bird.h"

Bird::Bird(TextureManager& manager) : textureManager(manager), flapSpeed(400.f), gravity(1800.f), velocity(0.f), shouldFlap(true), animationSpeed(0.2f),
	currentFrame(0), maxUpRot(-25.f), maxDownRot(50.f), rotationSpeed(200.f), invincible(false)
{
	texturesID = { "BIRD1", "BIRD2", "BIRD3" };

}

Bird::~Bird()
{
}

void Bird::initBird()
{
	birdSprite.setScale(BIRD_SCALE, BIRD_SCALE);
	birdSprite.setPosition(WIN_WIDTH/4, WIN_HEIGHT*0.33);
	birdSprite.setOrigin(birdSprite.getLocalBounds().width / 2.f, birdSprite.getLocalBounds().height / 2.f);
	birdSprite.setRotation(0.f);
}

void Bird::animate()
{
	if (animationClock.getElapsedTime().asSeconds() >= animationSpeed)
	{
		currentFrame++;
		if (currentFrame >= 3)
			currentFrame = 0;
		birdSprite.setTexture(textureManager.getTexture(texturesID[currentFrame]));
		animationClock.restart();
	}
}

void Bird::rotate(Time& dt)
{
	if (velocity >= 0)	// falling
		rotation = std::min(rotation + rotationSpeed * dt.asSeconds(), maxDownRot);
	else  // rising
		rotation = std::max(rotation - rotationSpeed * dt.asSeconds(), maxUpRot);
	birdSprite.setRotation(rotation);
}

void Bird::updatePUP()
{
	if (invincible)
	{
		if (pupTimer.getElapsedTime().asSeconds() > pupDuration)
		{
			invincible = false;
			birdSprite.setColor(Color::White);
		}
	}
}

void Bird::flap(Time& dt)
{
	velocity = -flapSpeed;
	rotation = maxUpRot;
}

void Bird::init()
{
	birdSprite.setTexture(textureManager.getTexture("BIRD1"));
	initBird();
}

void Bird::update(Time& dt)
{
	if(shouldFlap)
	{
		// Apply gravity
		// velocity in px/s, gravity in px/s^2 (frame-rate independent)
		velocity += gravity * dt.asSeconds();
		birdSprite.move(0.f, velocity * dt.asSeconds());

		if (Keyboard::isKeyPressed(Keyboard::Space))
			flap(dt);

		rotate(dt);

		animate();
		updatePUP();
	}
}

void Bird::render(RenderWindow* window)
{
	window->draw(birdSprite);
}

void Bird::setPosition(const float x, const float y)
{
	birdSprite.setPosition(x, y);
}

float Bird::getLeftEdge()
{
	return birdSprite.getGlobalBounds().left;
}

FloatRect Bird::getBounds() const
{
	return birdSprite.getGlobalBounds();
}

void Bird::applyInvincibility(const float duration)
{
	invincible = true;
	pupTimer.restart();
	pupDuration = duration;
	birdSprite.setColor(Color(255, 255, 255, 128));
}

bool Bird::getInvincibility() const
{
	return invincible;
}

void Bird::freeze()
{
	shouldFlap = false;
	velocity = 0.0;
}

void Bird::unfreeze()
{
	shouldFlap = true;
}

void Bird::reset()
{
	birdSprite.setPosition(WIN_WIDTH / 4, WIN_HEIGHT * 0.33);

	shouldFlap = true;
	velocity = 0.f;

	currentFrame = 0;
	birdSprite.setTexture(textureManager.getTexture(texturesID[0]));
	animationClock.restart();

	birdSprite.setRotation(0.f);

	invincible = false;
	birdSprite.setColor(Color::White); // reset transparency
}
