#pragma once
#include "../Entities/Enemy.h"
class Bat :public Enemy
{
public:
    Bat(float positionX, float positionY, float sizeX, float sizeY);
    ~Bat();
    void Movement() override;
    void Row() override;
    void Update() override;
	Projectile* CreateProjectile() override { return nullptr; }
private:
    double x;
};