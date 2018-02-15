#include <iostream>
#include "Ai.h"
#include "Global.h"

Ai::Ai(){
	init();
}

void Ai::init() {
	Entity::init();
	shape.setPosition(sf::Vector2f(WIN_W-64.0f,WIN_H/2.0f));
	speed *= 2.5;
}

void Ai::tick() {
	Entity::tick();
	move();
}

void Ai::move(){
	//Entity::move();
	sf::Vector2f pos = shape.getPosition();
	sf::Vector2f size = shape.getSize();

	sf::Vector2f ballPos = BALL->shape.getPosition();
	sf::Vector2f ballSize = BALL->shape.getSize();

	float diff = pos.y + size.y / 2 - ballPos.y + ballSize.y / 2;

	if(diff >= 45 && diff <= 90) {
		yDir = 0;
	}else if(pos.y > ballPos.y){
		yDir = -1;
	}else if(pos.y < ballPos.y){
		yDir = 1;
	}
}