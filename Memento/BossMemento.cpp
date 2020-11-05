#include "BossMemento.h"
#include <iostream>

BossMemento::BossMemento(float pX, float pY, float sX, float sY, unsigned int life,
	float cMovement, bool sMovement, float dX, float dY, float vX, float vY) {
	this->positionX = pX;
	this->positionY = pY;
	this->sizeX = sX;
	this->sizeY = sY;
	this->life = life;
	this->cooldownSwitchMovement = cMovement;
	this->switchMovement = sMovement;
	this->directionX = dX;
	this->directionY = dY;
	this->velocityX = vX;
	this->velocityY = vY;
}

BossMemento::~BossMemento()
{
}

BossMemento BossMemento::loadFromFile(std::istream& file) {
	BossMemento bossmemento;
	file >> bossmemento.positionX >> bossmemento.positionY >> bossmemento.sizeX >> bossmemento.sizeY >> bossmemento.life >>
		bossmemento.cooldownSwitchMovement >> bossmemento.switchMovement >> 
		bossmemento.directionX >> bossmemento.directionY >> bossmemento.velocityX >> bossmemento.velocityY;
	return bossmemento;
}

void BossMemento::saveToFile(std::ostream& file) {
	file << positionX << ' ' << positionY << ' ' << sizeX << ' ' << sizeY << ' ' <<
		life << ' ' << cooldownSwitchMovement << ' '	<< switchMovement << ' ' << 
		directionX << ' ' << directionY << ' ' << velocityX << ' '  << velocityY <<'\n';
}
