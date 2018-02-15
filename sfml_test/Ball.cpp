#include "Ball.h"
#include <iostream>

#include "Global.h"

Ball::Ball(){
	init();
}

void Ball::init(){
	float ballW=32.0,ballH=32.0;

	shape.setSize(sf::Vector2f(ballW,ballH));
	shape.setPosition(sf::Vector2f(WIN_W/2-ballW/2,WIN_H/2-ballH/2));
	
	//srand(time(NULL));
	//xDir = rand() % 2;
	//if(xDir == 0) xDir = -1;
	xDir = -1;
		
	yDir = 0;
	yV = 0;
}

void Ball::tick() {
	Entity::tick();
	move();
}

void Ball::bounds(){
	sf::Vector2f ballPos = shape.getPosition();
	sf::Vector2f ballSize = shape.getSize();
	// AI point
	if(ballPos.x <= 0) {
		AI->score++;
		init();
	}
	// Player point
	if(ballPos.x + ballSize.x >= WIN_W){
		PLAYER->score++;
		init();
	}

	if(ballPos.y <= 0){
		yDir = 1;
	}else if (ballPos.y+ballSize.y >= WIN_H){
		yDir = -1;
	}
}

void Ball::move(){
	srand(time(NULL));
	
	if(intersects(PLAYER)){
		BALL->xV /= 1.25;
		BALL->xDir = 1;

		yDir = rand() % 2;
		if (yDir == 0) yDir = -1;
		BALL->yV *= 1.05;
	}else if (intersects(AI)) {
		BALL->xV *= 1.25;
		BALL->xDir = -1;

		yDir = rand() % 2;
		if (yDir == 0) yDir = -1;
		BALL->yV *= 1.05;
	}

	bounds();
}