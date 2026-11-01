#include "Pipe.h"

void Pipe::initTextures()
{
	pipeTopSprite.setTexture(textureManager.getTexture("PIPE_TOP"));
	pipeBottomSprite.setTexture(textureManager.getTexture("PIPE_BOTTOM"));

	pipeTopSprite.setScale(PIPE_SCALE, PIPE_SCALE);
	pipeBottomSprite.setScale(PIPE_SCALE, PIPE_SCALE);
}

void Pipe::initPipe(const float& randomOffset)
{
	pipeBottomSprite.setPosition(WIN_WIDTH, randomOffset);
	pipeTopSprite.setPosition(WIN_WIDTH, randomOffset - pipeDistance - PIPE_SCALE * PIPE_HEIGHT);
}

Pipe::Pipe(TextureManager& manager, const int& distance, const float& speed, const int& randomOffset) :
	textureManager(manager), pipeDistance(distance), pipeSpeed(speed), passed(false)
{
	initTextures();
	initPipe(randomOffset);
}

Pipe::~Pipe()
{
}

void Pipe::update(Time& dt)
{
	float dx = pipeSpeed * dt.asSeconds();
	pipeTopSprite.move(-dx, 0.f);
	pipeBottomSprite.move(-dx, 0.f);
}

void Pipe::render(RenderWindow* window)
{
	window->draw(pipeBottomSprite);
	window->draw(pipeTopSprite);
}

void Pipe::setSpeed(const float& speed)
{
	pipeSpeed = speed;
}

void Pipe::setDistance(const int& distance)
{
	pipeDistance = distance;
}

const bool Pipe::isOutside()
{
	// true once the pipe's right edge leaves the screen
	return pipeBottomSprite.getGlobalBounds().left + pipeBottomSprite.getGlobalBounds().width < 0;
}

Sprite Pipe::getBottomSprite()
{
	return pipeBottomSprite;
}

Sprite Pipe::getTopSprite()
{
	return pipeTopSprite;
}

FloatRect Pipe::getBottomBounds() const
{
	return pipeBottomSprite.getGlobalBounds();
}

FloatRect Pipe::getTopBounds() const
{
	return pipeTopSprite.getGlobalBounds();
}

float Pipe::getRightEdge()
{
	return pipeBottomSprite.getGlobalBounds().left + pipeBottomSprite.getGlobalBounds().width;
}

bool Pipe::isPassed() const
{
	return passed;
}

void Pipe::setPassed()
{
	passed = true;
}
