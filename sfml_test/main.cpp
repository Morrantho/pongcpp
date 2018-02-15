#include <SFML/Graphics.hpp>
#include <iostream>
#include "Input.h"
#include "Entity.h"
#include "Player.h"
#include "Ball.h"
#include "Global.h"

int main(){
	sf::RenderWindow window(sf::VideoMode(WIN_W,WIN_H),"Pang", sf::Style::Default);
	window.setFramerateLimit(66);

	if (!SCORE_FONT->loadFromFile("computer_pixel-7.ttf"))
		return 1;

	PLAYER_SCORE_TEXT->setFont(*SCORE_FONT);
	PLAYER_SCORE_TEXT->setCharacterSize(96);
	PLAYER_SCORE_TEXT->setPosition(sf::Vector2f(WIN_W/2-128.0f,0.0f));

	AI_SCORE_TEXT->setFont(*SCORE_FONT);
	AI_SCORE_TEXT->setCharacterSize(96);
	AI_SCORE_TEXT->setPosition(sf::Vector2f(WIN_W/2+128.0f,0.0f));

	while (window.isOpen()){
		sf::Event event;
		
		while (window.pollEvent(event)){
			switch (event.type) {
				case sf::Event::KeyPressed:
					PLAYER->input.keyDown(event.key.code);
					break;
				case sf::Event::KeyReleased:
					PLAYER->input.keyUp(event.key.code);
					break;
				case sf::Event::Closed:
					window.close();
					break;
			}
		}

		window.clear();
			PLAYER->tick();
			PLAYER->render(&window);

			AI->tick();
			AI->render(&window);

			BALL->tick();
			BALL->render(&window);

			PLAYER_SCORE_TEXT->setString(std::to_string(PLAYER->score));
			AI_SCORE_TEXT->setString(std::to_string(AI->score));

			window.draw(*PLAYER_SCORE_TEXT);
			window.draw(*AI_SCORE_TEXT);
		window.display();
	}

	return 0;
}