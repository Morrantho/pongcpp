#pragma once

#include <SFML/Graphics.hpp>
#include "ents.h"

class Entity {
	public:
		sf::RectangleShape shape;
		float xV = 0.0f;
		float yV = 0.0f;
		int dir = 0;
		float speed = 2.0f;
		float cap = 4.0f;
		float damping = speed * 2.0f;

		Entity();
		void tick();
		void render(sf::RenderWindow *window);
		void move();
		bool intersects(Entity *e);
};