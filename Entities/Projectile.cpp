#include "Projectile.h"
#include "../Managers/CollisionManager.h"

Projectile::Projectile(unsigned int i, float speed, float pX, float pY, float sX, float sY, bool faceRight, float range, bool fromPlayer):
	Entity(){
	this->id = i;
	this->type = "Projectile";
	this->positionX = pX;
	this->positionY = pY;
	this->sizeX = sX;
	this->sizeY = sY;
	this->window->InitializeBody(id, positionX, positionY, sizeX, sizeY);
	this->collider->AddtoVector(this);
	this->range = range;
	this->rangeCount = 0.0f;
	this->speed = speed;
	this->faceRight = faceRight;
	this->fromPlayer = fromPlayer;
}

Projectile::~Projectile()
{
}

void Projectile::Update(){
	if (faceRight){
		positionX += this->speed * window->getDeltaTime();
	}
	else{
		positionX -= this->speed * window->getDeltaTime();
	}
	//recebe a mesma coisa que positionX porém começa em 0
	this->rangeCount += this->speed * window->getDeltaTime();
	window->Update(id, positionX, positionY, 0, faceRight);
}
