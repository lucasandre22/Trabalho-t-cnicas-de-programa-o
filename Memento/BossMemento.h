#pragma once
#include "Memento.h"
class BossMemento :
	public Memento
{
public:
	BossMemento(float pX = 0.0f, float pY = 0.0f, float sX = 0.0f, float sY = 0.0f, unsigned int life = 0, 
		float cMovement = 0.0f, bool sMovement = false, float dX = 0.0f, float dY = 0.0f, float vX = 0.0f, float vY = 0.0f);
	~BossMemento();
	static BossMemento loadFromFile(std::istream& file);
	void saveToFile(std::ostream& file);
	const float getPositionX() { return this->positionX; }
	const float getPositionY() { return this->positionY; }
	const float getSizeX() { return this->sizeX; }
	const float getSizeY() { return this->sizeY; }
	const unsigned int getLife() { return this->life; }
	const float getCooldownSwitchMovement() { return this->cooldownSwitchMovement; }
	const bool getSwitchMovement() { return this->switchMovement; }
	const float getDirectionX() { return this->directionX; }
	const float getDiretionY() { return this->directionY; }
	const float getVelocityX() { return this->velocityX; }
	const float getVelocityY() { return this->velocityY; }
private:
	float positionX;
	float positionY;
	float sizeX;
	float sizeY;
	unsigned int life;
	float cooldownSwitchMovement;
	bool switchMovement;
	float directionX;
	float directionY;
	float velocityX;
	float velocityY;
};

