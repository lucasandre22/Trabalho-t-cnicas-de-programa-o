#pragma once

#include "../Lists/EntityList.h"
#include "../Entities/Portal.h"
#include "../Entities/Enemy.h"
#include "../Entities/Player1.h"
#include "../Entities/Player2.h"
class CollisionManager
{
public:
	static CollisionManager* getInstance();
	~CollisionManager();
	void Clear();
	void Collided();
	void AddtoVector(Entity* e) { pairvector.emplace_back(e); }
	vector<Entity*>getPairVector() { return this->pairvector; }
private:
	static CollisionManager* instance;
	CollisionManager();
	bool Colliding(Entity* e1, Entity* e2);
	vector<Entity*>pairvector;
	float deltaX;
	float deltaY;
	float intersectX;
	float intersectY;
	EntityList* entList;
};


