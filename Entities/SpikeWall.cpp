#include "SpikeWall.h"
#include "../Managers/CollisionManager.h"

SpikeWall::SpikeWall(float positionX, float positionY, float sizeX, float sizeY) :
	Obstacle(){
	this->id = window->generateID("spikewall");
	this->type = "SpikeWall";
	this->positionX = positionX;
	this->positionY = positionY;
	this->sizeX = sizeX;
	this->sizeY = sizeY;
	this->window->InitializeBody(id, positionX, positionY, sizeX, sizeY);
	this->collider->AddtoVector(this);
	this->life = 3;
}

SpikeWall::~SpikeWall()
{
}

void SpikeWall::Update(){
	window->Update(id, positionX, positionY, 0, false);
}

SpikeWallMemento SpikeWall::createMemento() {
	SpikeWallMemento memento(this->positionX, this->positionY, this->sizeX, this->sizeY, this->life);
	return memento;
}

void SpikeWall::loadMemento(SpikeWallMemento* memento){
	this->positionX = memento->getPositionX();
	this->positionY = memento->getPositionY();
	this->sizeX = memento->getSizeX();
	this->sizeY = memento->getSizeY();
	this->life = memento->getLife();
	this->window->InitializeBody(id, positionX, positionY, sizeX, sizeY);
}
