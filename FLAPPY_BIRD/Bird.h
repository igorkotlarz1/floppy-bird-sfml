#ifndef BIRD_H
#define BIRD_H

#include "Definitions.h"
#include <vector>

using namespace sf;

class Bird
{
private:
	//Tekstury
	std::vector<Texture> Textures;
	Sprite birdSprite;

	//Animacja ptaka
	unsigned int currentFrame;
	float animationSpeed;
	Clock animationClock;

	//Rotacja ptaka
	float rotationSpeed, rotation, maxUpRot, maxDownRot;

	//Parametry fizyczne
	float flapSpeed, gravity, velocity;
	bool shouldFlap;

	//Power upy
	bool invincible; //, shrunk
	float pupDuration;
	Clock pupTimer;

	void initTextures();
	void initBird();

	void animate();
	void flap(Time& dt);
	void rotate(Time& dt);

	void updatePUP();

public:
	Bird();
	~Bird();

	void update(Time& dt); 

	void render(RenderWindow* window);

	//settery, gettery
	void setPosition(const float x, const float y);
	float getLeftEdge();
	FloatRect getBounds() const;

	void applyInvincibility(const float duration); 
	bool getInvincibility() const;

	void freeze();
	void unfreeze();
	void reset();
};

#endif 



