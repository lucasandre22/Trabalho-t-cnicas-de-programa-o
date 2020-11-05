#include "Enemy.h"

Enemy::Enemy():
	Character(){
	this->player1 = nullptr;
	this->player2 = nullptr;
	this->waitforlastanimationtodelete = false; 
	this->enemyShoots = true; 
	this->sightRangeX = 0.0f; 
	this->sightRangeY = 0.0f;
}

void Enemy::Dead(){
	if (life == 0) {
		this->row = 2;
		this->waitforlastanimationtodelete = true;
		this->imortalCount += window->getDeltaTime();
		if (this->imortalCount > 0.4f) {
			this->alive = false;
		}
	}
}

void Enemy::Shoot() {
	if (this->enemyShoots && this->alive && !this->attacking) {
		if (abs((player1->getPositionX() - this->positionX)) < this->sightRangeX &&
			abs((player1->getPositionY() - this->positionY)) < this->sightRangeY ||
			abs((player2->getPositionX() - this->positionX)) < this->sightRangeX &&
			abs((player2->getPositionY() - this->positionY)) < this->sightRangeY) {
			enemyFaceRight();
			this->attacking = true;
			CreateProjectile();
		}
	}
}

void Enemy::enemyFaceRight() {
	if (player1->getPositionX() - this->positionX < 0) {
		this->faceRight = false;
	}
	else {
		this->faceRight = true;
	}
}