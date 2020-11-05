#pragma once
#include "Memento.h"
class Player2Memento :
	public Memento
{
public:
	Player2Memento(float positionX = 0.0f, float positionY = 0.0f);
	~Player2Memento();
	static Player2Memento loadFromFile(std::istream& file);
	void saveToFile(std::ostream& file);
	const float getPositionX() { return this->positionX; };
	const float getPositionY() { return this->positionY; };
private:
	float positionX;
	float positionY;
};
