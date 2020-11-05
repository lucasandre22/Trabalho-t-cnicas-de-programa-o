#pragma once
#include "Memento.h"

class Player1Memento :
	public Memento
{
public:
	Player1Memento(float positionX = 0.0f, float positionY = 0.0f, unsigned int life = 0, unsigned int score = 0);
	~Player1Memento();
	static Player1Memento loadFromFile(std::istream& file);
	void saveToFile(std::ostream& file);
	const float getPositionX() { return this->positionX; };
	const float getPositionY() { return this->positionY; };
	unsigned int getLife() { return this->life; };
	unsigned int getScore() { return this->score; };
private:
	float positionX;
	float positionY;
	unsigned int life;
	unsigned int score;
};
