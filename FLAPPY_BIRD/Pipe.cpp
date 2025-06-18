#include "Pipe.h"



void Pipe::initTextures()
{
	if (!pipeBottomTexture.loadFromFile(R"(Textures\pipes\pipe_up.png)") || !pipeTopTexture.loadFromFile(R"(Textures\pipes\pipe_down.png)"))
		std::cout << "ERROR: Loading pipes texture!\n";

	pipeTopSprite.setTexture(pipeTopTexture);
	pipeBottomSprite.setTexture(pipeBottomTexture);

	pipeTopSprite.setScale(PIPE_SCALE, PIPE_SCALE);
	pipeBottomSprite.setScale(PIPE_SCALE, PIPE_SCALE);
}

void Pipe::initPipe(const float& randomOffset)
{
	pipeBottomSprite.setPosition(WIN_WIDTH, randomOffset);
	pipeTopSprite.setPosition(WIN_WIDTH, randomOffset - pipeDistance - PIPE_SCALE * PIPE_HEIGHT);

	//wersja dzialajaca
	/*float gapCenterY = randomOffset;

	float topPos = gapCenterY - (pipeDistance / 2) - 1.5*PIPE_HEIGHT;
	float bottomPos = gapCenterY + (pipeDistance / 2);

	pipeTopSprite.setPosition(WIN_WIDTH, topPos);
	pipeBottomSprite.setPosition(WIN_WIDTH, bottomPos);*/
}

Pipe::Pipe(const int& distance, const float& speed, const int& randomOffset) : pipeDistance(distance), pipeSpeed(speed), passed(false)
{
	initTextures();
	initPipe(randomOffset);
}

Pipe::Pipe() : pipeDistance(200), pipeSpeed(200)
{
	initTextures();
	initPipe(0.f);
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
	//true jezeli prawy obrys rury wyjedzie poza ekran
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
