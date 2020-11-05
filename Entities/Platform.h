#pragma once
#include "../Memento/PlatformMemento.h"
#include "Entity.h"
class Platform: public Entity
{
public:
	Platform(float positionX = 0, float positionY = 0, float SizeX = 0, float SizeY = 0);
	~Platform();
	PlatformMemento createMemento();
	void loadMemento(PlatformMemento* memento);

private:
	virtual void Update() {}
};

