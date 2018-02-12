#include "EntityList.h"

EntityList::EntityList() {
	head = NULL;
}

void EntityList::add(Entity e) {
	EntityNode * ptr = head;

	EntityNode *newNode;
	newNode->next = NULL;
	newNode->value = e;

	if(ptr == NULL){
		ptr->value = e;
		ptr->next = NULL;
		head = ptr;
	}else{
		while (ptr != NULL){
			ptr = ptr->next;
		}
		
		elems++;
		ptr = newNode;
	}
}

int EntityList::size(){
	return this->elems;
}
