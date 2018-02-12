#pragma once

#include "Entity.h"

class EntityNode{
	public:
		Entity value;
		EntityNode * next;

		EntityNode(Entity e);
};
