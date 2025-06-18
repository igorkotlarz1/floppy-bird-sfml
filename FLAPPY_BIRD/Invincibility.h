#ifndef INVINCIBILITY_H
#define INVINCIBILITY_H

#include "PowerUp.h"

class Invincibility : public PowerUp
{
private:	
	void initTextures();

public:
	Invincibility(const Vector2f& position);

	void apply(Bird& bird) override;

};

#endif 



