#include "PipeFactory.h"

//inicjalizacja zmiennej do sledzenia 
int PipeFactory::nextMovingPipeScore = PipeFactory::randomIntGenerator(1, 7);

int PipeFactory::randomIntGenerator(const int& min, const int& max)
{
    static std::random_device rd;
    std::uniform_int_distribution<int> dist(min, max);

    return dist(rd);
}

PipeFactory::PipeFactory() : movingPipeSpeed(50.f), movingPipeRange(100)
{
    baseDistance = PIPE_DISTANCE;
    baseSpeed = PIPE_SPEED;
}

std::unique_ptr<Pipe> PipeFactory::createPipe(unsigned int score, Difficulty diff)
{
    switch (diff)
    {
    case Difficulty::EASY:
        break;
    case Difficulty::MEDIUM:
        baseSpeed *= 1.2f;
        baseDistance -= 25;
        break;
    case Difficulty::HARD:
        baseSpeed *= 1.5f;
        baseDistance -= 50;
        break;
    }
    //dzielenie calkowite -> co 10 pkt predkosc rosnie o 10
    //                       co 10 pkt dystans maleje o 10

    float speed = baseSpeed + (score / 10) * 10; 
    float distance = baseDistance - (score / 10) * 10;

    float movingSpeed =movingPipeSpeed + (score / 10) * 5;
    float movingRange = movingPipeRange + (score / 10) * 5;

    float offset = randomIntGenerator(250, 650);

    if (score >= nextMovingPipeScore)
    {
        nextMovingPipeScore = score + randomIntGenerator(1, 7);
        return std::make_unique<MovingPipe>(distance, speed, offset, movingSpeed, movingRange);
    }

    return std::make_unique<Pipe>(distance, speed, offset);
}
