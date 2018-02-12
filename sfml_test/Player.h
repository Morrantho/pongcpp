#pragma once

#include "Entity.h"
#include "Input.h"

class Player:public Entity{
	public:
		Player();
		Input input;
};