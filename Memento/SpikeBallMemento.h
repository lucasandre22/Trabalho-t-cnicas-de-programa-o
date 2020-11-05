#pragma once
#include "Memento.h"
class SpikeBallMemento :
	public Memento
{
public:
	SpikeBallMemento(float positionX = 0.0f, float positionY = 0.0f, float sizeX = 0.0f, float sizeY = 0.0f, float initialY = 0.0f);
	~SpikeBallMemento();
	static SpikeBallMemento loadFromFile(std::istream& file);
	void saveToFile(std::ostream& file);
	const float getPositionX() { return this->positionX; };
	const float getPositionY() { return this->positionY; };
	const float getSizeX() { return this->sizeX; }
	const float getSizeY() { return this->sizeY; }
	const float getInitialY() { return this->initialY; };
private:
	float positionX;
	float positionY;
	float sizeX;
	float sizeY;
	float initialY;
};

