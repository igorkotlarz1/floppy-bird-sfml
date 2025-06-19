#include "PipeFactory.h"

int PipeFactory::nextMovingPipeScore = PipeFactory::randomIntGenerator(1, 7);

int PipeFactory::randomIntGenerator(const int& min, const int& max)
{
    static std::random_device rd;
    std::uniform_int_distribution<int> dist(min, max);

    return dist(rd);
}

PipeFactory::PipeFactory(TextureManager& manager) : textureManager(manager), movingPipeSpeed(50.f), movingPipeRange(100)
{
    baseDistance = PIPE_DISTANCE;
    baseSpeed = PIPE_SPEED;
}

std::unique_ptr<Pipe> PipeFactory::createPipe(unsigned int score) 
{
    float speed = baseSpeed + (score / 10) * 10; 
    float distance = baseDistance - (score / 10) * 10;

    float movingSpeed =movingPipeSpeed + (score / 10) * 5;
    float movingRange = movingPipeRange + (score / 10) * 5;

    float offset = randomIntGenerator(250, 650);

    if (score >= nextMovingPipeScore)
    {
        nextMovingPipeScore = score + randomIntGenerator(1, 7);
        return std::make_unique<MovingPipe>(textureManager, distance, speed, offset, movingSpeed, movingRange);
    }

    return std::make_unique<Pipe>(textureManager, distance, speed, offset);
}
