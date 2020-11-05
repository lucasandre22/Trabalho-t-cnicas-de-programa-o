#include "Bat.h"
#include <math.h>
#include "../Managers/CollisionManager.h"

Bat::Bat(float positionX, float positionY, float sizeX, float sizeY){
	this->id = window->generateID("bat");
	this->type = "Bat";
	this->positionX = positionX;
	this->positionY = positionY;
	this->sizeX = sizeX;
	this->sizeY = sizeY;
	this->window->InitializeBody(this->id, this->positionX, this->positionY, this->sizeX, this->sizeY);
	this->collider->AddtoVector(this);
	this->life = 1;
	this->x = 0.0f;
	this->enemyShoots = false;
	this->velocityX = -300.0f;

}

Bat::~Bat()
{
}

void Bat::Movement()
{
	this->x += 0.01;
	this->velocityY = (float)sin(x) * 300;
	Move(this->velocityX * window->getDeltaTime(), this->velocityY * window->getDeltaTime());
}

void Bat::Row(){
	this->row = 0;
	if (!this->alive) {
		this->row = 2;
	}
}

void Bat::Update(){
	if (this->alive && !this->waitforlastanimationtodelete) {
		Damage();
		Movement();
		Row();
		Dead();
		FaceRight();
		window->Update(this->id, this->positionX, this->positionY, this->row, this->faceRight);
	}
	else {
		Row();
		Dead();
		window->Update(this->id, this->positionX, this->positionY, this->row, this->faceRight);
	}
}
