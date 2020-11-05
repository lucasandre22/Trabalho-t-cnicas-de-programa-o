#pragma once
#include "Memento.h"
class WizardMemento :
	public Memento
{
public:
	WizardMemento(float positionX = 0.0f, float positionY = 0.0f, float sizeX = 0.0f, float sizeY = 0.0f, float initialX = 0.0f, unsigned int life = 0);
	~WizardMemento();
	static WizardMemento loadFromFile(std::istream& file);
	void saveToFile(std::ostream& file);
	const float getPositionX() { return this->positionX; };
	const float getPositionY() { return this->positionY; };
	const float getSizeX() { return this->sizeX; }
	const float getSizeY() { return this->sizeY; }
	const float getInitialX() { return this->initialX; };
	unsigned int getLife() { return this->life; };
private:
	float positionX;
	float positionY;
	float sizeX;
	float sizeY;
	float initialX;
	unsigned int life;
};

