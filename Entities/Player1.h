#pragma once
#include "Player.h"
#include "../Memento/Player1Memento.h"
class Player1:public Player{
public:
	Player1(float positionX = 0.0f , float positionY = 0.0f, float sizeX = 0.0f, float sizeY = 0.0f);
	~Player1(){}
	void Update() override;
	void Movement() override;
	Projectile* CreateProjectile() override;
	const bool Shooting() override;
	Player1Memento createMemento();
	void loadMemento(Player1Memento* memento);
	void setJumping(const bool jump) { this->jumping = jump; }
	static unsigned int score;
private:
	const bool moveRight() override { return this->window->D(); }
	const bool moveLeft() override { return this->window->A(); }
	const bool moveUp() override { return this->window->W(); }
	bool jumping;
	float jumpHeight;
};