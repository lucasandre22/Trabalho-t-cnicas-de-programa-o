#pragma once
#include "Entity.h"
#include "Projectile.h"
class Character : public Entity
{
public:
	Character();
	~Character() {}
	const bool getAlive() { return this->alive; }
	void setVelocityY(const float v) { this->velocityY = v; }
	void setTakingDamage(const bool dmg) { this->takingDamage = dmg; }
protected:
	virtual void Update() = 0;
	virtual void Movement() = 0;
	virtual void Row() = 0;
	virtual Projectile* CreateProjectile() = 0;
	void FaceRight() { if (this->velocityX > 0.0f) { this->faceRight = true; } if (this->velocityX < 0.0f) { this->faceRight = false; } }
	void Damage() { if (takingDamage) { this->life--;	this->takingDamage = false; } }
    float velocityX;
    float velocityY;
    float speed;
	float imortalCount;
    float cooldown;
	float cooldownCount;
    bool faceRight;
    bool attacking;
    bool alive;
	bool takingDamage;
    unsigned int life;
    unsigned int row;
};
