#include "Player1Memento.h"
#include <iostream>

Player1Memento::Player1Memento(float positionX, float positionY, unsigned int life, unsigned int score) :
	Memento() {
	this->positionX = positionX;
	this->positionY = positionY;
	this->life = life;
	this->score = score;
}

Player1Memento::~Player1Memento()
{
}

Player1Memento Player1Memento::loadFromFile(std::istream& file)
{
	Player1Memento pl1Memento;
	file >> pl1Memento.positionX >> pl1Memento.positionY >> pl1Memento.life >> pl1Memento.score;
	return pl1Memento;
}

void Player1Memento::saveToFile(std::ostream& file)
{
	file << positionX << ' ' << positionY << ' ' << life << ' ' << score << '\n';
}
