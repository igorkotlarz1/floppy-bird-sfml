#ifndef MOVINGPIPE_H
#define MOVINGPIPE_H

#include "Pipe.h"

class MovingPipe : public Pipe
{
private:
	bool movingUp;
	float moveRange, moveSpeed, startY;
public:
	MovingPipe(TextureManager& manager, const int& distance, const float& speed, const int& randomOffset,
		float moveSpeed, float moveRange);
	~MovingPipe();

	void update(Time& dt) override;
};

#endif 




