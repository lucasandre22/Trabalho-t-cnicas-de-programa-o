#include "Character.h"
Character::Character():
    Entity(){
	this->velocityX = 0.0f;
	this->velocityY = 0.0f;
	this->speed = 0.0f;
	this->imortalCount = 0.0f;
	this->cooldownCount = 0.0f;
	this->cooldown = 0.0f;
	this->faceRight = false;
	this->attacking = false;
	this->alive = true;
	this->takingDamage = false;
	this->life = 0;
	this->row = 0;
}



