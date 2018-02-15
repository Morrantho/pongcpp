#ifndef GLOBAL_H
#define GLOBAL_H

#include "Player.h"
#include "Ai.h"
#include "Ball.h"

#define WIN_W 1024
#define WIN_H 768

extern sf::Font *SCORE_FONT;
extern sf::Text *PLAYER_SCORE_TEXT;
extern sf::Text *AI_SCORE_TEXT;
extern Player *PLAYER;
extern Ai *AI;
extern Ball *BALL;

#endif // !GLOBAL_H
