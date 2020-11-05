#pragma once
#include "Memento.h"
class SpikeWallMemento :
	public Memento
{
public:
	SpikeWallMemento(float positionX = 0.0f, float positionY = 0.0f, float sizeX = 0.0f, float sizeY = 0.0f, unsigned int life = 0);
	~SpikeWallMemento();
	static SpikeWallMemento loadFromFile(std::istream& file);
	void saveToFile(std::ostream& file);
	const float getPositionX() { return this->positionX; }
	const float getPositionY() { return this->positionY; }
	const float getSizeX() { return this->sizeX; }
	const float getSizeY() { return this->sizeY; }
	const unsigned int getLife() { return this->life; }
private:
	float positionX;
	float positionY;
	float sizeX;
	float sizeY;
	unsigned int life;
};

