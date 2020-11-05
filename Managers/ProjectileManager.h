#pragma once
#include "../Entities/Projectile.h"
#include "../Entities/Player1.h"
#include "../Entities/Player2.h"
#include "../Lists/ProjectileList.h"
#include "../Lists/EntityList.h"
#include "../Lists/EnemyList.h"
#include "../Managers/GraphicManager.h"
class ProjectileManager
{
public:
	ProjectileManager();
	~ProjectileManager();
	void manageProjectiles();
	void setListProjectile(ProjectileList* p) { this->projList = p; }
	void setListEntity(EntityList* e) { this->entList = e; }
	void setPl1(Player1* p) { this->player1 = p; }
	void setPl2(Player2* p) { this->player2 = p; }
	void setEneList(EnemyList* e) { this->eneList = e; }

private:
	void outOfRangeCheck();
	void AddProjectile(Projectile* p);
	void RemoveProjectile(Projectile* p);
	void Player1Shooting();
	void Player1Cooldown();
	void Player2Shooting();
	void Player2Cooldown();
	void EnemyShooting();
	void enemyFaceRight(Enemy* e);
	float cooldownCountPlayer1;
	float cooldownCountPlayer2;
	GraphicManager* window;
	EntityList* entList;
	ProjectileList* projList;
	EnemyList* eneList;
	Player1* player1;
	Player2* player2;
};

