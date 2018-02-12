#include <SFML/Graphics.hpp>
#include <iostream>
#include "Input.h"
#include "Entity.h"
#include "Player.h"
#include "ents.h"

int main(){
	const int width = 1024;
	const int height = 768;

	sf::RenderWindow window(sf::VideoMode(width,height),"Pang", sf::Style::Default);
	window.setFramerateLimit(60);

	Player pad;

	while (window.isOpen()){
		sf::Event event;
		
		while (window.pollEvent(event)){

			switch (event.type) {
				case sf::Event::KeyPressed:
					pad.input.keyDown(event.key.code);
					break;
				case sf::Event::KeyReleased:
					pad.input.keyUp(event.key.code);
					break;
				case sf::Event::Closed:
					window.close();
					break;
			}
		}

		window.clear();

		ents::getInstance().tick();
		ents::getInstance().render(&window);

		//pad.tick();
		//pad.render(&window);
		window.display();
	}

	return 0;
}