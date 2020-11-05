#include "SpikeBall.h"
#include "../Managers/CollisionManager.h"

SpikeBall::SpikeBall(float positionX, float positionY, float sizeX, float sizeY, float initialY)
	: Obstacle()
{
	this->id = window->generateID("spikeball");
	this->type = "SpikeBall";
	this->positionX = positionX;
	this->positionY = positionY;
	this->sizeX = sizeX;
	this->sizeY = sizeY;
	this->window->InitializeBody(id, positionX, positionY, sizeX, sizeY);
	this->collider->AddtoVector(this);
	this->velocityY = 100.0f;
	this->initialY = initialY;
	this->initialVelocityY = velocityY;

}

SpikeBall::~SpikeBall()
{
}

void SpikeBall::Movement(){
	if (this->positionY > (this->initialY + 40.0f)) {
		this->velocityY = -initialVelocityY;
	}
	else if (this->positionY < (this->initialY - 40.0f)) {
		this->velocityY = initialVelocityY;
	}
	Move(0.0f, velocityY * window->getDeltaTime());
}

void SpikeBall::Update(){
	Movement();
	window->Update(id, positionX, positionY, 0, false);
}

SpikeBallMemento SpikeBall::createMemento(){
	SpikeBallMemento memento(this->positionX, this->positionY, this->sizeX, this->sizeY, this->initialY);
	return memento;
}

void SpikeBall::loadMemento(SpikeBallMemento* memento){
	this->positionX = memento->getPositionX();
	this->positionY = memento->getPositionY();
	this->sizeX = memento->getSizeX();
	this->sizeY = memento->getSizeY();
	this->initialY = memento->getInitialY();
	this->window->InitializeBody(id, positionX, positionY, sizeX, sizeY);
}
