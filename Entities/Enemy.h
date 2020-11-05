#pragma once
#include "../Entities/Character.h"
#include "../Entities/Player1.h"
#include "../Entities/Player2.h"
class Player1;
class Player2;
class Enemy :public Character
{
public:
	Enemy();
    ~Enemy() {}
	virtual Projectile* CreateProjectile() = 0;
	//diferencia inimigos que atiram de outros
	const bool getEnemyShoots() { return this->enemyShoots; } 
	//distancia em que o inimigo detecta o player
	const float getSightRangeX() { return this->sightRangeX; }
	const float getSightRangeY() { return this->sightRangeY; }
	void setPlayer1(Player1* p) { this->player1 = p; }
	void setPlayer2(Player2* p) { this->player2 = p; }
protected:
	void Dead();
	void Shoot();
	void enemyFaceRight();
	virtual void Update() = 0;
	bool waitforlastanimationtodelete;
	bool enemyShoots;
	float sightRangeX;
	float sightRangeY;
	Player1* player1;
	Player2* player2;
};