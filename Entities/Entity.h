#pragma once
#include "../Managers/GraphicManager.h"
using namespace np_GraphicManager;
class CollisionManager;
class EntityList;
class Entity
{ 
protected:
    float positionX;
    float positionY;
    float sizeX;
    float sizeY;
	unsigned int id;
	GraphicManager* window;
	CollisionManager* collider;
	EntityList* enlist;
	string type;

public:
    Entity();
    ~Entity();
	const float getPositionX() { return positionX; }
	const float getPositionY() { return positionY; }
	const float getHalfSizeX() { return sizeX / 2; }
	const float getHalfSizeY() { return sizeY / 2; }
	const string getType() { return this->type; }
	void setPosition(const float pX, const float pY) { positionX = pX;	positionY = pY; }
	void setSize(const float sX, const float sY) { sizeX = sX;	sizeY = sY; }
	void Move(float dx, float dy) { positionX += dx;	positionY += dy; }
	void Draw();
	virtual void Update() = 0;
};


