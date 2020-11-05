#include "Platform.h"
#include "../Managers/CollisionManager.h"

Platform::Platform(float pX, float pY, float sX, float sY):
    Entity()
{
	this->id = window->generateID("platform");
	this->type = "Platform";
	this->positionX = pX;
	this->positionY = pY;
	this->sizeX = sX;
	this->sizeY = sY;
	this->window->InitializeBody(id, positionX, positionY, sizeX, sizeY);
	this->collider->AddtoVector(this);

}
Platform::~Platform()
{
}

PlatformMemento Platform::createMemento(){
	PlatformMemento memento(this->positionX, this->positionY, this->sizeX, this->sizeY);
	return memento;
}

void Platform::loadMemento(PlatformMemento* memento){
	this->positionX = memento->getPositionX();
	this->positionY = memento->getPositionY();
	this->sizeX = memento->getSizeX();
	this->sizeY = memento->getSizeY();
	this->window->InitializeBody(id, positionX, positionY, sizeX, sizeY);
}


