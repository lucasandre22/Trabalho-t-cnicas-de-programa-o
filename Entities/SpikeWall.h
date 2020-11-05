#pragma once
#include "Obstacle.h"
#include "../Memento/SpikeWallMemento.h"
class SpikeWall : public Obstacle
{
private:
	unsigned int life;
public:
	SpikeWall(float positionX = 0.0f, float positionY = 0.0f, float sizeX = 0.0f, float sizeY = 0.0f);
	~SpikeWall();
	void Update() override;
	void Damage() { this->life--; }
	const unsigned int getLife() { return this->life; }
	SpikeWallMemento createMemento();
	void loadMemento(SpikeWallMemento* memento);
};

