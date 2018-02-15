#ifndef AI_H
#define AI_H

#include "Entity.h"

class Ai:public Entity{
public:
	Ai();
	void init();
	void tick();
	void move();
};

#endif // !AI_H
