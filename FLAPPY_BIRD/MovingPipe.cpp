#include "MovingPipe.h"

MovingPipe::MovingPipe(const int& distance, const float& speed, const int& randomOffset, float moveSpeed, float moveRange) 
	: Pipe(distance, speed, randomOffset), moveRange(moveRange), moveSpeed(moveSpeed), movingUp(true)
{
	startY = pipeBottomSprite.getPosition().y;
}

MovingPipe::~MovingPipe()
{

}

void MovingPipe::update(Time& dt)
{
	// tak jak zwykla rura
	float dx = pipeSpeed * dt.asSeconds();
	float dy = moveSpeed * dt.asSeconds();

	pipeTopSprite.move(-dx, 0.f);
	pipeBottomSprite.move(-dx, 0.f);

	if (movingUp)
	{
		pipeBottomSprite.move(0.f, -dy);
		pipeTopSprite.move(0.f, -dy);

		if (pipeBottomSprite.getPosition().y < startY - moveRange) // gorna granica ruchu wzgledem startu
			movingUp = false;
	}
	else
	{
		pipeBottomSprite.move(0.f, dy);
		pipeTopSprite.move(0.f, dy);

		if (pipeBottomSprite.getPosition().y > startY + moveRange) // dolna granica ruchu wzgledem startu
			movingUp = true;
	}

}
