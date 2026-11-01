#include "PowerUp.h"

void PowerUp::animate(Time& dt)
{
	float dx = 2* moveSpeed * dt.asSeconds();
	float dy = moveSpeed * dt.asSeconds();

	sprite.move(-dx, 0.f);

	if (movingUp)
	{
		sprite.move(0.f, -dy);
		if (sprite.getPosition().y < startY - moveRange) // upper bound of the movement
			movingUp = false;
	}
	else
	{
		sprite.move(0.f, dy);
		if (sprite.getPosition().y > startY + moveRange) // lower bound of the movement
			movingUp = true;
	}
}

PowerUp::PowerUp(TextureManager& manager, const Vector2f& position) :  textureManager(manager), active(false), movingUp(true), duration(7.f), elapsedTime(0.f), moveRange(20), moveSpeed(50.f)
{
	sprite.setPosition(position);
	startY = position.y;
}

void PowerUp::update(Time& dt)
{
	if (active)
	{
		elapsedTime += dt.asSeconds();
		if (elapsedTime > duration)
			active = false;
	}
	animate(dt);
}

void PowerUp::render(RenderWindow* window)
{
	if (!active)
		window->draw(sprite);
}

bool PowerUp::isActive() const
{
	return active;
}

void PowerUp::activate()
{
	active = true;
	elapsedTime = 0.f;
}

FloatRect PowerUp::getBounds() const
{
	return sprite.getGlobalBounds();
}

bool PowerUp::isOutside() const
{
	return sprite.getGlobalBounds().left + sprite.getGlobalBounds().width < 0;
}
