#include "Player2.h"
#include "../Managers/CollisionManager.h"

Player2::Player2(float positionX, float positionY, float sizeX, float sizeY, bool playable):
	Player()
{
	this->id = window->generateID("player2");
	this->type = "Player2";
	this->positionX = positionX;
	this->positionY = positionY;
	this->sizeX = sizeX;
	this->sizeY = sizeY;
	this->window->InitializeBody(id, positionX, positionY, sizeX, sizeY);
	this->collider->AddtoVector(this);
	this->player1 = nullptr;
	this->rangefromplayer1 = 150.0f;
	this->speed = 175.0f;
	this->cooldown = 1.25;
	if (!playable) {
		this->alive = false;
	}

}

Player2::~Player2()
{
}

void Player2::Movement(){
	this->velocityX *= 0.5f;
	this->velocityY *= 0.5f;
	if (moveLeft()) {
		this->velocityX -= this->speed;
	}
	else if (moveRight()) {
		this->velocityX += this->speed;
	}
	if (moveUp()) {
		this->velocityY -= this->speed;
	}
	else if (moveDown()) {
		this->velocityY += this->speed;
	}
}

void Player2::MovementRange(){
	if ((positionX - this->player1->getPositionX()) > rangefromplayer1) {
		this->positionX = this->player1->getPositionX() + rangefromplayer1;
	}
	else if ((positionX - this->player1->getPositionX()) < -rangefromplayer1) {
		this->positionX = this->player1->getPositionX() - rangefromplayer1;
	}
	if ((positionY - this->player1->getPositionY()) > rangefromplayer1) {
		this->positionY = this->player1->getPositionY() + rangefromplayer1;
	}
	else if ((positionY - this->player1->getPositionY()) < -rangefromplayer1) {
		this->positionY = this->player1->getPositionY() - rangefromplayer1;
	}
}

Projectile* Player2::CreateProjectile() {
	float firstPositionX = this->faceRight ? this->positionX + 2 * getHalfSizeX() : this->positionX - 2 * getHalfSizeX();
	float firstPositionY = this->positionY - 5.0f;
	return new Projectile(window->generateID("projectile4"), 1000.0f, firstPositionX, firstPositionY, 30.0f, 30.0f, this->faceRight, 600.0f, true);
}

void Player2::Update(){
	if (alive) {
		Movement();
		MovementRange();
		Shoot();
		ShootCooldown();
		Row();
		FaceRight();
		Move(this->velocityX * this->window->getDeltaTime(), this->velocityY * this->window->getDeltaTime());
		window->Update(id, positionX, positionY, row, faceRight);
	}
	else {
		Move(this->velocityX * this->window->getDeltaTime(), this->velocityY * this->window->getDeltaTime());
		window->Update(id, positionX, positionY, row, faceRight);
	}
}

Player2Memento Player2::createMemento()
{
	Player2Memento memento(positionX, positionY);
	return memento;
}

void Player2::loadMemento(Player2Memento* memento){
	this->positionX = memento->getPositionX();
	this->positionY = memento->getPositionY();
}

