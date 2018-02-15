#ifndef BALL_H
#define BALL_H

#include "Entity.h"

class Ball:public Entity{
public:
	Ball();
	void init();
	void tick();
	void bounds();
	void move();
};

#endif // !BALL_H
