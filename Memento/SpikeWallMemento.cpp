#include "SpikeWallMemento.h"

SpikeWallMemento::SpikeWallMemento(float positionX, float positionY, float sizeX, float sizeY, unsigned int life){
	this->positionX = positionX;
	this->positionY = positionY;
	this->sizeX = sizeX;
	this->sizeY = sizeY;
	this->life = life;
}

SpikeWallMemento::~SpikeWallMemento()
{
}

SpikeWallMemento SpikeWallMemento::loadFromFile(std::istream& file){
	SpikeWallMemento memento;
	file >> memento.positionX >> memento.positionY >> memento.sizeX >> memento.sizeY >> memento.life;
	return memento;
}

void SpikeWallMemento::saveToFile(std::ostream& file){
	file << positionX << ' ' << positionY << ' ' << sizeX << ' ' << sizeY << ' ' << life << '\n';
}
