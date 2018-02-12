#pragma once

#include "EntityNode.h"

class EntityList {
	private:
		int elems;
	public:
		EntityNode * head;

		EntityList();
		void add(Entity e);
		int size();
};
