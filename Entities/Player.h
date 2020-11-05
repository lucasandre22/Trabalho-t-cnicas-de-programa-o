#pragma once
#include "Character.h"

class Player: public Character
{
public:
	Player();
	~Player();
	void setAlive(bool al) { this->alive = al; }

protected:
	//Checa se o jogador está nas condições em que ele morre
	void Dead();
	//Muda a linha da sprite que contém a animação dos jogadores
	void Row();
	//Jogador fica imortal se perder pontos de vida
	void Imortal();
	//Checa se o jogador está em condições de atacar
	void Shoot();
	//Intervalo entre os ataques
	void ShootCooldown();
	
	virtual Projectile* CreateProjectile() = 0;
	virtual void Update() = 0;
	//Movimento dos jogadores
	virtual void Movement() = 0;
	//Input do teclado
	virtual const bool Shooting() = 0;
	virtual const bool moveRight() = 0;
	virtual const bool moveLeft() = 0;
	virtual const bool moveUp() = 0;
	bool imortal;
};

