#include "Portal.h"
#include "../Managers/CollisionManager.h"

Portal::Portal(float positionX, float positionY, float sizeX, float sizeY):
	Obstacle(){
	this->id = window->generateID("portal");
	this->type = "Portal";
	this->positionX = positionX;
	this->positionY = positionY;
	this->sizeX = sizeX;
	this->sizeY = sizeY;
	this->window->InitializeBody(id, positionX, positionY, sizeX, sizeY);
	this->collider->AddtoVector(this);
	this->player1 = nullptr;
}

Portal::~Portal()
{
}

void Portal::Teleport(){
	float x = -1150.0f; // posiçao em que começa as plataformas fixas
	x += ((rand() % 8) * 350.0f); // cai em alguma das 8 plataformas fixas, aleatoriamente
	this->player1->setPosition(x+50.0f, float(rand() % 400));
}

void Portal::Update(){
	window->Update(this->id, this->positionX, this->positionY, 0, false);
}

PortalMemento Portal::createMemento() {
	PortalMemento memento(this->positionX, this->positionY, this->sizeX, this->sizeY);
	return memento;
}

void Portal::loadMemento(PortalMemento* memento){
	this->positionX = memento->getPositionX();
	this->positionY = memento->getPositionY();
	this->sizeX = memento->getSizeX();
	this->sizeY = memento->getSizeY();
	this->window->InitializeBody(id, positionX, positionY, sizeX, sizeY);
}
