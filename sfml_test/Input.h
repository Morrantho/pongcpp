#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Entity.h"

class Input {
	public:
		Entity * ent;
		Input();
		void setEntity(Entity * ent);
		void keyDown(int code);
		void keyUp(int code);
};