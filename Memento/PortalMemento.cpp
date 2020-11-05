#include "PortalMemento.h"

PortalMemento::PortalMemento(float positionX, float positionY, float sizeX, float sizeY){
	this->positionX = positionX;
	this->positionY = positionY;
	this->sizeX = sizeX;
	this->sizeY = sizeY;
}

PortalMemento::~PortalMemento()
{
}

PortalMemento PortalMemento::loadFromFile(std::istream& file){
	PortalMemento memento;
	file >> memento.positionX >> memento.positionY >> memento.sizeX >> memento.sizeY;
	return memento;
}

void PortalMemento::saveToFile(std::ostream& file){
	file << positionX << ' ' << positionY << ' ' << sizeX << ' ' << sizeY << '\n';
}
