#ifndef POWERUP_H
#define POWERUP_H

#include "Definitions.h"
#include "Bird.h"
#include "TextureManager.h"

class PowerUp
{
protected:
	TextureManager& textureManager;

	Sprite sprite;

	bool active, movingUp;
	float duration, elapsedTime;
	float moveRange, moveSpeed, startY;

	void animate(Time& dt);

public:

	PowerUp(TextureManager& manager, const Vector2f& position);

	virtual void update(Time& dt);
	virtual void render(RenderWindow* window);

	virtual void apply(Bird& bird) = 0;

	virtual bool isActive() const;
	void activate();

	virtual FloatRect getBounds() const;
	virtual ~PowerUp() = default;

	bool isOutside() const;
};

#endif
