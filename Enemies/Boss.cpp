#include "Boss.h"
#include <fstream>
#include <math.h>
#include "../Managers/CollisionManager.h"

#define MINDISTANCE 800.0f

Boss::Boss(float pX, float pY, float sX, float sY) :
	Enemy()
{
	this->id = window->generateID("boss");
	this->type = "Boss";
	this->positionX = pX;
	this->positionY = pY;
	this->sizeX = sX;
	this->sizeY = sY;
	this->window->InitializeBody(id, positionX, positionY, sizeX, sizeY);
	this->collider->AddtoVector(this);
	this->velocityX = 1.0f;
	this->velocityY = 1.0f;
	this->speed = 1.0f;
	this->cooldown = 1.5f;
	this->life = 30;
	this->imortalCount = 0.0f;
	this->alive = true;
	this->waitforlastanimationtodelete = false;
	this->cooldownCountAttacks = 0.0f;
	this->cooldownCountSwitchMovement = 0.0f;
	this->switchMovement = false;
	this->directionX = 0.0f;
	this->directionY = 0.0f;
	this->sightRangeX = 900.0f;
	this->sightRangeY = 200.0f;

}

void Boss::Movement()
{
	this->directionX = this->player1->getPositionX() - positionX;
	this->directionY = this->player1->getPositionY() - positionY;
	//Aumenta a velocidade do boss se o jogador estiver longe
	this->directionX = (abs(directionX) > 800.0f) ? directionX * 0.45f : directionX * 0.15f;
	this->directionY = (directionY * 0.55f);
	//Mantém uma distância mínima do jogador
	if (this->directionX > 0) {
		this->faceRight = true;
		this->directionX -= 80.0f;
	}
	else {
		this->faceRight = false;
		this->directionX += 80.0f;
	}
	Move((directionX * velocityX * window->getDeltaTime()), (directionY * velocityY * window->getDeltaTime()));
	if (this->attacking) {
		cooldownCountAttacks += window->getDeltaTime();
		if (cooldownCountAttacks > cooldown)
		{
			cooldownCountAttacks = 0.0f;
			this->attacking = false;
		}
	}
}

void Boss::Movement2()
{
	FaceRight();
	Move((directionX * velocityX * window->getDeltaTime()), (directionY * velocityY * window->getDeltaTime()));
	if (abs(positionX - this->player1->getPositionX()) > 850.0f || abs(positionY - this->player1->getPositionY()) > 500.0f)
	{
		switchMovement = false;
	}
}

void Boss::Movement3()
{
	if (abs(positionX - 2400.0f) > 10) // move para extrema direita
	{
		velocityY = -100.f;
		Move((velocityX * 750) * window->getDeltaTime(), velocityY*(window->getDeltaTime()));
	}
	else{
		if (positionY >= 600.0f) {
			this->velocityY = -300.0f;
		}
		else if (positionY <= -100.0f) {
			this->velocityY = 300.0f;
		}
		Move(0.0f, velocityY * window->getDeltaTime());
		if (this->attacking) {
			cooldownCountAttacks += window->getDeltaTime();
			//Atira mais rápido
			if (cooldownCountAttacks > (cooldown / 3)){
				cooldownCountAttacks = 0.0f;
				this->attacking = false;
			}
		}
	}
}

void Boss::Row(){
	if (this->attacking) {
		this->row = 1; 
	}
	else if (!this->alive) {
		this->row = 2;
	}
	else {
		this->row = 0;
	}
}

void Boss::Update()
{
	if (this->alive && !this->waitforlastanimationtodelete) {
		Damage();
		if (this->life > 15)
		{
			cooldownCountSwitchMovement += window->getDeltaTime();
			if (!switchMovement && cooldownCountSwitchMovement > (cooldown * 5.5f))
			{
				switchMovement = true;
				cooldownCountSwitchMovement = 0.0f;
				this->directionX = (this->player1->getPositionX() - positionX);
				this->directionY = (this->player1->getPositionY() - positionY) + 170.0f;
			}
			if (!switchMovement)
				Movement(); // movimento normal do boss, segue o player.
			else
				Movement2(); // movimento em que o boss muda de lado na tela.
		}
		else
			Movement3(); // movimento quando estiver quase morrendo, vai para o canto da fase subindo e descendo.
		if (positionX > player1->getPositionX()) // arrumar um jeito sem esse if pro faceright
			faceRight = false;
		else
			faceRight = true;
		Row();
		Dead();
		Shoot();
		window->Update(this->id, this->positionX, this->positionY, this->row, this->faceRight);
	}
	else {
		Row();
		Dead();
		window->Update(this->id, this->positionX, this->positionY, this->row, this->faceRight);
	}
}


Projectile* Boss::CreateProjectile()
{
	unsigned int id = window->generateID("projectile3");
	int Ydeviation = rand() % 5 * 2 - 5;
	float firstPositionX = faceRight ? positionX + 2 * getHalfSizeX() : positionX - 2 * getHalfSizeX();
	float firstPositionY = positionY - getHalfSizeY() / 2 - Ydeviation;
	return new Projectile(id, 500.0f, firstPositionX, firstPositionY, 75.0f, 50.0f, faceRight, 1000.f, false);
}

BossMemento Boss::createMemento() {
	BossMemento memento(this->positionX, this->positionY, this->sizeX, this->sizeY, this->life, this->cooldownCountSwitchMovement,
		this->switchMovement, this->directionX, this->directionY, this->velocityX, this->velocityY);
	return memento;
}

void Boss::loadMemento(BossMemento* memento) {
	this->positionX = memento->getPositionX();
	this->positionY = memento->getPositionY();
	this->sizeX = memento->getSizeX();
	this->sizeY = memento->getSizeY();
	this->life = memento->getLife();
	this->cooldownCountSwitchMovement = memento->getCooldownSwitchMovement();
	this->directionX = memento->getDirectionX();
	this->directionY = memento->getDiretionY();
	this->velocityX = memento->getVelocityX();
	this->velocityY = memento->getVelocityY();
	this->window->InitializeBody(id, positionX, positionY, sizeX, sizeY);
}

