#include "PlatformMemento.h"

PlatformMemento::PlatformMemento(float positionX, float positionY, float sizeX, float sizeY){
	this->positionX = positionX;
	this->positionY = positionY;
	this->sizeX = sizeX;
	this->sizeY = sizeY;
}

PlatformMemento::~PlatformMemento()
{

}

PlatformMemento PlatformMemento::loadFromFile(std::istream& file){
	PlatformMemento memento;
	file >> memento.positionX >> memento.positionY >> memento.sizeX >> memento.sizeY;
	return memento;
}

void PlatformMemento::saveToFile(std::ostream& file){
	file << this->positionX << ' ' << this->positionY << ' ' << this->sizeX << ' ' << this->sizeY << '\n';
}
