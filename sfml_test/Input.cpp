#include "Input.h"
// A = 0, D = 3, S = 18, W = 22

Input::Input(){
}

void Input::setEntity(Entity *ent){
	this->ent = ent;
}

void Input::keyDown(int code){
	switch (code) {
		case 18:
			ent->dir = 1;
			break;
		case 22:
			ent->dir = -1;
			break;
	}
}

void Input::keyUp(int code) {
	ent->dir = 0;

	//switch (code){
	//	default:
	//		ent->dir = 0;
	//		break;
	//}
}
