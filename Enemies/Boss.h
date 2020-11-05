#pragma once

#include "../Entities/Enemy.h"
#include "../Entities/Projectile.h"
#include "../Memento/BossMemento.h"

class Boss : public Enemy
{
public:
    Boss(float positionX = 0.0f, float positionY = 0.0f, float sizeX = 0.0f, float sizeY = 0.0f);
    ~Boss(){}
    Projectile* CreateProjectile() override;
    BossMemento createMemento();
    void loadMemento(BossMemento* memento);
	void Update() override;
private:
	void Movement() override;
	void Movement2();
	void Movement3();
	void Row() override;
    float cooldownCountAttacks;
    float cooldownCountSwitchMovement;
    bool switchMovement;
    float directionX;
    float directionY;
};