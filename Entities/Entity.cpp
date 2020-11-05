#include "Entity.h"
#include "../Managers/CollisionManager.h"
Entity::Entity(){
	this->window = GraphicManager::getInstance();
	this->collider = CollisionManager::getInstance();
	this->enlist = EntityList::getInstance();
	this->enlist->Add(this);
    this->id = 0;
    this->positionX = 0.0f;
    this->positionY = 0.0f;
    this->sizeX = 0.0f;
    this->sizeY = 0.0f;
}

Entity::~Entity() { }

void Entity::Draw(){
	window->Draw(id);
}

