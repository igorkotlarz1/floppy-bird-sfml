#ifndef BIRD_H
#define BIRD_H

#include "Definitions.h"
#include <vector>
#include "TextureManager.h"

using namespace sf;

class Bird
{
private:
	// Textures
	TextureManager& textureManager;

	std::vector<std::string> texturesID;
	Sprite birdSprite;

	// Flap animation
	unsigned int currentFrame;
	float animationSpeed;
	Clock animationClock;

	// Rotation
	float rotationSpeed, rotation, maxUpRot, maxDownRot;

	// Physics
	float flapSpeed, gravity, velocity;
	bool shouldFlap;

	// Power-ups
	bool invincible;
	float pupDuration;
	Clock pupTimer;

	void initBird();

	void animate();
	void flap(Time& dt);
	void rotate(Time& dt);

	void updatePUP();

public:
	Bird(TextureManager& manager);

	~Bird();

	void init();
	void update(Time& dt);

	void render(RenderWindow* window);

	// Setters and getters
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
