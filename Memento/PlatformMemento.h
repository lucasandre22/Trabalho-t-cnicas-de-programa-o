#pragma once
#include "Memento.h"
class PlatformMemento :
	public Memento
{
public:
	PlatformMemento(float positionX = 0.0f, float positionY = 0.0f, float sizeX = 0.0f, float sizeY = 0.0f);
	~PlatformMemento();
	static PlatformMemento loadFromFile(std::istream& file);
	void saveToFile(std::ostream& file);
	const float getPositionX() { return this->positionX; }
	const float getPositionY() { return this->positionY; }
	const float getSizeX() { return this->sizeX; }
	const float getSizeY() { return this->sizeY; }
private:
	float positionX;
	float positionY;
	float sizeX; 
	float sizeY;
};

