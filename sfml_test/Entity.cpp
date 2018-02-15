#include "Global.h"
#include "Entity.h"
#include <iostream>

#include "Global.h"

Entity::Entity(){
	init();
}

void Entity::init() {
	shape = sf::RectangleShape();
	shape.setSize(sf::Vector2f(32.f, 96.f));
	shape.setPosition(sf::Vector2f(64.f, 32.f));

	score = 0;
}

void Entity::tick(){
	sf::Vector2f pos = shape.getPosition();

	pos.y += yV;
	pos.x += xV;

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

void Entity::bounds(){
	sf::Vector2f pos  = shape.getPosition();
	sf::Vector2f size = shape.getSize();
	
	if(pos.y <= 0){
		pos.y = 0;
	}else if(pos.y+size.y >= WIN_H){
		pos.y = WIN_H - size.y;
	}

	shape.setPosition(pos);
}

void Entity::move(){
	if(yDir == -1 && yV > -cap){ // Up
		yV -= speed;
	}else if(yDir== 0) { // Idle Y
		yV /= (1.0f + damping);
	}else if (yDir == 1 && yV < cap) { // Down
		yV += speed;
	}

	if (xDir == -1 && xV > -cap) { // Left
		xV -= speed;
	}else if (xDir == 0) { // Idle X
		xV /= (1.0f + damping);
	}else if (xDir == 1 && xV < cap) { // Right
		xV += speed;
	}

	bounds();
}