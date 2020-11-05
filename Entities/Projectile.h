#pragma once
#include "Entity.h"
#include "../Lists/EntityList.h"
#include "../Lists/ProjectileList.h"
class EntityList;
class ProjectileList;
class Projectile:public Entity
{
public:
	Projectile(unsigned int id, float speed, float positionX, float positionY, float sizeX, float sizeY, bool facingRight, float range, bool fromPlayer);
	~Projectile();
	void Update();
	const bool getfromPlayer() { return this->fromPlayer; }
	const float getRange() { return this->range; }
	const float getRangeCount() { return this->rangeCount; }
private:
	float speed;
	float rangeCount;
	float range;
	bool faceRight;
	bool fromPlayer;
};

