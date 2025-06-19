#include "Invincibility.h"

void Invincibility::initTextures()
{
	sprite.setTexture(textureManager.getTexture("INVINC"));
	sprite.setScale(PUP_SCALE, PUP_SCALE);
}

Invincibility::Invincibility(TextureManager& manager, const Vector2f& position) : PowerUp(manager, position)
{
	initTextures();
}


void Invincibility::apply(Bird& bird)
{
	bird.applyInvincibility(duration);
}

