#include "Bird.h"

Bird::Bird() : flapSpeed(400.f), gravity(20.f), velocity(0.f), shouldFlap(true), animationSpeed(0.2f), 
	currentFrame(0), maxUpRot(-25.f), maxDownRot(50.f), rotationSpeed(200.f), invincible(false)
{
	initTextures();
	initBird();
}

Bird::~Bird()
{
}

void Bird::initTextures()
{
	Texture texture1, texture2, texture3;
	texture1.loadFromFile(BRID_PATH_1);
	texture2.loadFromFile(BRID_PATH_2);
	texture3.loadFromFile(BRID_PATH_3);

	Textures.push_back(texture1);
	Textures.push_back(texture2);
	Textures.push_back(texture3);

	birdSprite.setTexture(Textures[0]);
	birdSprite.setScale(BIRD_SCALE, BIRD_SCALE); 
}

void Bird::initBird()
{
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

		birdSprite.setTexture(Textures[currentFrame]);
		animationClock.restart();
	}
}

void Bird::rotate(Time& dt)
{
	if (velocity >= 0)	//opadamy
		rotation = std::min(rotation + rotationSpeed * dt.asSeconds(), maxDownRot);
	else  //wznosimy sie ku gorze
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
	velocity = -flapSpeed * dt.asSeconds();
	rotation = maxUpRot;
}

void Bird::update(Time& dt)
{	
	if(shouldFlap)
	{
		//Dzialanie 'grawitacji'
		velocity += gravity * dt.asSeconds();
		birdSprite.move(0.f, velocity);

		if (Keyboard::isKeyPressed(Keyboard::Space))
			flap(dt);

		if (velocity >= 0)	//wznosimy sie ku gorze
			rotation = std::min(rotation + rotationSpeed * dt.asSeconds(), maxDownRot);
		else //opadamy
			rotation = std::max(rotation - rotationSpeed * dt.asSeconds(), maxUpRot);
		birdSprite.setRotation(rotation);

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
	birdSprite.setTexture(Textures[0]);
	animationClock.restart();

	birdSprite.setRotation(0.f);

	invincible = false;
	birdSprite.setColor(Color::White); // wyzerowanie przezroczystosci
}
