#pragma once
#include "Obstacle.h"
#include "Player1.h"
#include "../Memento/PortalMemento.h"
class Portal:public Obstacle
{
public:
	Portal(float positionX= 0.0f, float positionY = 0.0f, float sizeX = 0.0f, float sizeY = 0.0f);
	~Portal();
	void Teleport();
	void Update();
	void setPlayer1(Player1* p) { this->player1 = p; }
	PortalMemento createMemento();
	void loadMemento(PortalMemento* memento);
private:
	Player1* player1;
};