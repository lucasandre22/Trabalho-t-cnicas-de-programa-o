#pragma once
#include "Player.h"
#include "Player1.h"
#include "../Memento/Player2Memento.h"

class Player2:public Player{
public:
	Player2(float positionX = 0.0f, float positionY = 0.0f, float sizeX = 0.0f, float sizeY = 0.0f, bool playable = false);
	~Player2();
	Projectile* CreateProjectile() override;
	void Update() override;
	void Movement() override;
	void setPlayer1(Player1* p1) { player1 = p1; }
	const bool Shooting() override { return this->window->RSHIFT(); }
	void damageToPlayer1() { this->player1->setTakingDamage(true); }
	Player2Memento createMemento();
	void loadMemento(Player2Memento* memento);

private:
	//Limita o movimento do jogandor 2 para uma área em volta do player
	void MovementRange();
	const bool moveRight() override { return this->window->RIGHT(); }
	const bool moveLeft() override { return this->window->LEFT(); }
	const bool moveUp() override { return this->window->UP(); }
	const bool moveDown() { return this->window->DOWN(); }
	Player1* player1;
	float rangefromplayer1;
};

