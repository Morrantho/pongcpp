#pragma once

#include <vector>
#include "Entity.h"
#include "EntityList.h"

class ents {
	private:
		static ents instance;
		EntityList alive;
		ents();
	public:
		static ents getInstance();
		
		EntityList getAll();
		void tick();
		void render(sf::RenderWindow * window);
};
