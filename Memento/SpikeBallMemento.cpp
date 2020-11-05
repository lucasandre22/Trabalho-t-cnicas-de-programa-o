#include "SpikeBallMemento.h"

SpikeBallMemento::SpikeBallMemento(float positionX, float positionY, float sizeX, float sizeY, float initialY){
	this->positionX = positionX;
	this->positionY = positionY;
	this->sizeX = sizeX;
	this->sizeY = sizeY;
	this->initialY = initialY;
}

SpikeBallMemento::~SpikeBallMemento()
{
}

SpikeBallMemento SpikeBallMemento::loadFromFile(std::istream& file){
	SpikeBallMemento memento;
	file >> memento.positionX >> memento.positionY >> memento.sizeX >> memento.sizeY >> memento.initialY;
	return memento;
}

void SpikeBallMemento::saveToFile(std::ostream& file){
	file << positionX << ' ' << positionY << ' ' << sizeX << ' ' << sizeY << ' ' << initialY << '\n';
}
