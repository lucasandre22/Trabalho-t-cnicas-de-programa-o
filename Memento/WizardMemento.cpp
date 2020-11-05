#include "WizardMemento.h"
#include <iostream>
WizardMemento::WizardMemento(float positionX, float positionY, float sizeX, float sizeY, float initialX, unsigned int life){
	this->positionX = positionX;
	this->positionY = positionY;
	this->sizeX = sizeX;
	this->sizeY = sizeY;
	this->initialX = initialX;
	this->life = life;
}

WizardMemento::~WizardMemento()
{
}

WizardMemento WizardMemento::loadFromFile(std::istream& file){
	WizardMemento wizardMemento;
	file >> wizardMemento.positionX >> wizardMemento.positionY >> wizardMemento.sizeX >> wizardMemento.sizeY >> wizardMemento.initialX >> wizardMemento.life;
	return wizardMemento;
}

void WizardMemento::saveToFile(std::ostream& file){
	file << this->positionX << ' ' << this->positionY << ' ' << this->sizeX << ' ' << this->sizeY << ' ' << this->initialX << ' ' << this->life << '\n';
}
