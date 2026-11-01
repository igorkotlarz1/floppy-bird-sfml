#include "MovingPipe.h"

MovingPipe::MovingPipe(TextureManager& manager, const int& distance, const float& speed, const int& randomOffset, float moveSpeed, float moveRange)
	: Pipe(manager, distance, speed, randomOffset), moveRange(moveRange), moveSpeed(moveSpeed), movingUp(true)
{
	startY = pipeBottomSprite.getPosition().y;
}

MovingPipe::~MovingPipe()
{

}

void MovingPipe::update(Time& dt)
{
	// Move left like a regular pipe
	float dx = pipeSpeed * dt.asSeconds();
	float dy = moveSpeed * dt.asSeconds();

	pipeTopSprite.move(-dx, 0.f);
	pipeBottomSprite.move(-dx, 0.f);

	if (movingUp)
	{
		pipeBottomSprite.move(0.f, -dy);
		pipeTopSprite.move(0.f, -dy);

		if (pipeBottomSprite.getPosition().y < startY - moveRange) // upper bound of the movement
			movingUp = false;
	}
	else
	{
		pipeBottomSprite.move(0.f, dy);
		pipeTopSprite.move(0.f, dy);

		if (pipeBottomSprite.getPosition().y > startY + moveRange) // lower bound of the movement
			movingUp = true;
	}
}
