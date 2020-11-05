#include "Player1.h"
#include "../Managers/CollisionManager.h"
unsigned int Player1::score = 0;
Player1::Player1(float positionX, float positionY, float sizeX, float sizeY) :
	Player(){
	this->id = window->generateID("player1");
	this->type = "Player1";
	this->positionX = positionX;
	this->positionY = positionY;
	this->sizeX = sizeX;
	this->sizeY = sizeY;
	this->window->InitializeBody(id, positionX, positionY, sizeX, sizeY);
	this->collider->AddtoVector(this);
	this->speed = 150.0f;
	this->jumping = false;
	this->jumpHeight = 150.0f;
	this->life = 300;
	this->alive = true;
	this->cooldown = 0.25;
	this->imortal = false;
	this->imortalCount = 0.0f;
}

void Player1::Movement(){
	this->velocityX *= 0.5f;
	this->velocityY += 2 * 981.0f * window->getDeltaTime();
	if (moveLeft()) {
		this->velocityX -= this->speed;
	}
	else if (moveRight()) {
		this->velocityX += this->speed;
	}
	if (moveUp() && this->jumping) {
		this->jumping = false;
		this->velocityY = -sqrt(4.0f * 981.0f * this->jumpHeight);
	}
	Move(this->velocityX * this->window->getDeltaTime(), this->velocityY * this->window->getDeltaTime());
}

Projectile* Player1::CreateProjectile() {
	float firstPositionX = this->faceRight ? this->positionX + 2 * getHalfSizeX() : this->positionX - 2 * getHalfSizeX();
	float firstPositionY = this->positionY - 5.0f;
	return new Projectile(window->generateID("projectile1"), 1000.0f, firstPositionX, firstPositionY, 100.0f, 100.0f, this->faceRight, 600.0f, true);
}

const bool Player1::Shooting(){
	return this->window->SPACE();
}

void Player1::Update()
{
	Dead();
	Imortal();
	Row();
	FaceRight();
	Movement();
	Shoot();
	ShootCooldown();
	if (!imortal)
		Damage();
	window->Update(id, positionX, positionY, row, faceRight);
}

Player1Memento Player1::createMemento(){
	Player1Memento memento(positionX, positionY, life, score);
	return memento;
}

void Player1::loadMemento(Player1Memento* memento){
	this->positionX = memento->getPositionX();
	this->positionY = memento->getPositionY();
	this->life = memento->getLife();
	this->score = memento->getScore();
}
