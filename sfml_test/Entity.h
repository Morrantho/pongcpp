#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

class Entity {
public:
	sf::RectangleShape shape;
	float xV = 0.0f;
	float yV = 0.0f;
	int yDir = 0;
	int xDir = 0;
	float speed = 2.0f;
	float cap = 4.0f;
	float damping = speed * 2.0f;
	int score;

	Entity();
	void init();
	void tick();
	void render(sf::RenderWindow *window);
	void bounds();
	void move();
	bool intersects(Entity *e);
};

#endif // !ENTITY_H