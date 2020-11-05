#pragma once
#include "../Entities/Entity.h"

class Obstacle :public Entity 
{
protected:
	virtual void Update() = 0;
public:
	Obstacle() : Entity() { }
	~Obstacle() {}
};