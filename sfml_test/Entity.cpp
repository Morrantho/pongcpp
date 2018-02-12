#include "Entity.h"

Entity::Entity(){
	this->shape = sf::RectangleShape();
	this->shape.setSize(sf::Vector2f(32.f, 96.f));
	this->shape.setPosition(sf::Vector2f(32.f, 32.f));


}

void Entity::tick(){
	sf::Vector2f pos = shape.getPosition();

	pos.y += yV;

	shape.setPosition(pos);

	move();
}

void Entity::render(sf::RenderWindow *window){
	window->draw(this->shape);
}

bool Entity::intersects(Entity *e){
	sf::Vector2f ePos = e->shape.getPosition();
	sf::Vector2f eScl = e->shape.getSize();

	sf::Vector2f pos = shape.getPosition();
	sf::Vector2f scl = shape.getSize();

	return pos.x < ePos.x+eScl.x &&
	ePos.x < pos.x + scl.x &&
	pos.y < ePos.y + eScl.y &&
	ePos.y < pos.y + scl.y;
}

void Entity::move(){
	if(dir == -1 && yV > -cap){ // Up
		yV -= speed;
	}else if(dir== 0) { // Idle
		yV /= (1.0f + damping);
	}else if (dir == 1 && yV < cap) { // Down
		yV += speed;
	}
}