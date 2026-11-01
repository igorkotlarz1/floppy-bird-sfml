#ifndef PIPEFACTORY_H
#define PIPEFACTORY_H

#include <memory>
#include <random>
#include "Pipe.h"
#include "MovingPipe.h"
#include "GameState.h"
#include "Definitions.h"
#include "TextureManager.h"

class PipeFactory
{
private:
	TextureManager& textureManager;

	// Base pipe parameters
	float baseSpeed, baseDistance;
	float movingPipeSpeed, movingPipeRange; // moving pipes only

	static int nextMovingPipeScore;

public:

	PipeFactory(TextureManager& manager);

	std::unique_ptr<Pipe> createPipe(unsigned int score);
	static void resetMovingPipeSchedule();
	static int randomIntGenerator(const int& min, const int& max);
};

#endif
