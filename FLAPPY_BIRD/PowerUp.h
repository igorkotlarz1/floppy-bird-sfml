#ifndef POWERUP_H
#define POWERUP_H

#include "Definitions.h"
#include "Bird.h"

class PowerUp
{
protected:
	Sprite sprite;
	Texture texture;

	bool active, movingUp;
	float duration, elapsedTime;
	float moveRange, moveSpeed, startY;

	void animate(Time& dt);

public:
	PowerUp(const Vector2f& position);
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


