#include "EntityList.h"
#include "../Entities/Entity.h"
EntityList* EntityList::instance = 0;
EntityList* EntityList::getInstance(){
	if (instance == 0) {
		instance = new EntityList;
	}
	return instance;
}
