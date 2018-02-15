#ifndef INPUT_H
#define INPUT_H

#include <SFML/Graphics.hpp>
#include "Entity.h"

class Input {
public:
	Entity * ent;
	Input();
	void setEntity(Entity * ent);
	void keyDown(int code);
	void keyUp(int code);
};

#endif // !INPUT_H