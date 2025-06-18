#include "Invincibility.h"

void Invincibility::initTextures()
{
	if (!texture.loadFromFile(INVINC_PATH))
		std::cout << "ERROR: failed to load INVINCIBILITY TEXTURE" << std::endl;

	sprite.setTexture(texture);
	sprite.setScale(PUP_SCALE, PUP_SCALE);
}

Invincibility::Invincibility(const Vector2f& position) : PowerUp(position)
{
	initTextures();
}


void Invincibility::apply(Bird& bird)
{
	bird.applyInvincibility(duration);
}

