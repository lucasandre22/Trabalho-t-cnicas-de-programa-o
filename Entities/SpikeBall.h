#pragma once
#include "Obstacle.h"
#include "../Memento/SpikeBallMemento.h"
class SpikeBall : public Obstacle
{
public:
	SpikeBall(float positionX = 0.0f, float positionY = 0.0f, float sizeX = 0.0f, float sizeY = 0.0f, float initialY = 0.0f);
	~SpikeBall();
	void Movement();
	void Update() override;
	SpikeBallMemento createMemento();
	void loadMemento(SpikeBallMemento* memento);
private:
	float velocityY;
	float initialY;
	float initialVelocityY;
};

