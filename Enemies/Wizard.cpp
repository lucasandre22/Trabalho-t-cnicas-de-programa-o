#include "Wizard.h"
#include "../Managers/CollisionManager.h"

Wizard::Wizard(float pX, float pY, float sX, float sY, float initialX) :
	Enemy(){
	if (rand() % 2 == 1) { this->id = window->generateID("wizardGreen"); }
	else { this->id = window->generateID("wizardRed"); }
	this->type = "Wizard";
	this->positionX = pX;
	this->positionY = pY;
	this->sizeX = sX;
	this->sizeY = sY;
	this->window->InitializeBody(id, positionX, positionY, sizeX, sizeY);
	this->collider->AddtoVector(this);
	this->velocityX = 50.0f;
	this->life = 3;
	this->initialX = pX;
	this->alive = true;
	this->waitforlastanimationtodelete = false;
	this->sightRangeX = 300.0f;
	this->sightRangeY = 30.0f;
	this->faceRight = true;
	this->cooldown = 0.7f;
	this->initialX = initialX;
	this->randVelocity = rand() % 20 + 30;

}

void Wizard::Movement(){
    if (this->positionX >= (this->initialX + 58.0f)) {
        this->faceRight = false;
        this->velocityX = (float)-randVelocity;
    }
    else if (this->positionX < (this->initialX - 58.0f)) {
        this->faceRight = true;
        this->velocityX = (float)randVelocity;
    }
    if (this->attacking) {
        this->velocityX = 0.0f;
        cooldownCount += window->getDeltaTime();
        if (cooldownCount > cooldown){
            cooldownCount = 0.0f;
            this->velocityX = (float)randVelocity;
            this->attacking = false;
        }
    }
    Move(velocityX * window->getDeltaTime(), this->velocityY);
}



void Wizard::Row(){
	this->row = 0;
	if (this->attacking) {
		this->row = 1;
	}
	if(!this->alive){
		this->row = 2;
	}
}

void Wizard::Update(){
	if (this->alive && !this->waitforlastanimationtodelete) {
		Damage();
		Row();
		if (!this->attacking) {
			FaceRight();
		}
		Movement();
		Shoot();
		Dead();
		window->Update(this->id, this->positionX, this->positionY, this->row, this->faceRight);
	}
	else {
		this->attacking = true;
		Row();
		Dead();
		window->Update(this->id, this->positionX, this->positionY, this->row, this->faceRight);
	}
}

Projectile* Wizard::CreateProjectile(){
	float firstPositionX = faceRight ? positionX + 2 * getHalfSizeX() : positionX - 2 * getHalfSizeX();
	float firstPositionY = positionY - 5.0f;
	return new Projectile(window->generateID("projectile2"), 350.0f, firstPositionX, firstPositionY, 50.0f, 50.0f, faceRight, 500.0f, false);
}

WizardMemento Wizard::createMemento(){
	WizardMemento memento(this->positionX, this->positionY, this->sizeX, this->sizeY, this->initialX, this->life);
	return memento;
}

void Wizard::loadMemento(WizardMemento* memento){
	this->positionX = memento->getPositionX();
	this->positionY = memento->getPositionY();
	this->sizeX = memento->getSizeX();
	this->sizeY = memento->getSizeY();
	this->initialX = memento->getInitialX();
	this->life = memento->getLife();
	this->window->InitializeBody(id, positionX, positionY, sizeX, sizeY);
}
