#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include "Input.h"

class Player:public Entity{
public:
	Player();
	Input input;
};

#endif // !PLAYER_H