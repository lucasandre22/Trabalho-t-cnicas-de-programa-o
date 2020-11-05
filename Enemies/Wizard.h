#pragma once
#include "../Entities/Enemy.h"
#include "../Entities/Projectile.h"
#include "../Memento/WizardMemento.h"
class Wizard : public Enemy
{
public:
    Wizard(float positionX = 0.0f, float positionY = 0.0f, float sizeX = 0.0f, float sizeY = 0.0f, float initialX = 0.0f);
	~Wizard() {}
    void Movement() override;
    void Row() override;
    void Update() override;
    Projectile* CreateProjectile() override;
	WizardMemento createMemento();
	void loadMemento(WizardMemento* memento);
private:
	//posição em que o inimigo foi inicializado
    float initialX;
    int randVelocity;
};