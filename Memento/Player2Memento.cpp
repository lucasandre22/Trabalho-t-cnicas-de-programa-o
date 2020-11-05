#include "Player2Memento.h"
#include <iostream>

Player2Memento::Player2Memento(float positionX, float positionY) :
	Memento() {
	this->positionX = positionX;
	this->positionY = positionY;
}

Player2Memento::~Player2Memento()
{
}

Player2Memento Player2Memento::loadFromFile(std::istream& file)
{
	Player2Memento pl2Memento;
	file >> pl2Memento.positionX >> pl2Memento.positionY;
	return pl2Memento;
}

void Player2Memento::saveToFile(std::ostream& file)
{
	file << positionX << ' ' << positionY << '\n';
}
