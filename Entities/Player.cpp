#include "Player.h"

Player::Player() :
    Character(){
	this->imortal = false;
}

Player::~Player()
{
}

void Player::Dead(){
	if (positionY > 1000.0 || life == 0) {
		this->alive = false;
	}
}

void Player::Row() {
	this->row = 0;
	if (this->attacking) {
		this->row = 1;
	}
	if (this->imortal) {
		this->row = 2;
	}
}

void Player::Imortal(){
	if (this->takingDamage && this->life > 1) {
		this->imortal = true;
	}
	if (this->imortal) {
		this->imortalCount += window->getDeltaTime();
		if (imortalCount > 1.5f) {
			this->imortalCount = 0.0f;
			this->imortal = false;
		}
	}
}

void Player::Shoot(){
	if (Shooting() && this->alive && !this->attacking) {
		CreateProjectile();
		this->attacking = true;
	}
}

void Player::ShootCooldown() {
	cooldownCount += window->getDeltaTime();
	if (cooldownCount > this->cooldown) {
		cooldownCount = 0.0f;
		this->attacking = false;
	}
}
