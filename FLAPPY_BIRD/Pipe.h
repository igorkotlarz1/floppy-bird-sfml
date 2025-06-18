#ifndef PIPE_H
#define PIPE_H

#include "Definitions.h"

class Pipe
{
protected:
	Texture pipeBottomTexture, pipeTopTexture;
	Sprite pipeBottomSprite, pipeTopSprite;

	int pipeDistance;
	float pipeSpeed;

	void initPipe(const float& randomOffset);
	void initTextures();
	
	bool passed;

public:

	Pipe(const int& distance, const float& speed, const int& randomOffset);
	Pipe();
	
	virtual ~Pipe();

	virtual void update(Time &dt); //const RenderWindow* window,
	void render(RenderWindow* window);

	void setSpeed(const float& speed);
	void setDistance(const int& distance);

	const bool isOutside();
	Sprite getBottomSprite();
	Sprite getTopSprite();

	FloatRect getBottomBounds() const;
	FloatRect getTopBounds() const;


	float getRightEdge();
	bool isPassed() const;
	void setPassed();
};


#endif

