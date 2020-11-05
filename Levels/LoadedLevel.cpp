#include "LoadedLevel.h"

LoadedLevel::LoadedLevel()
{
	this->id = window->generateID("background");
	this->positionX = 0.0f;
	this->positionY = 290.0f;
	this->sizeX = 6000.0f;
	this->sizeY = 1200.0f;
	window->InitializeBody(id, positionX, positionY, sizeX, sizeY);
	EntityList.Add(static_cast<Entity*>(this));
	GeneratePlayer2(false);
	loadPlayer1();
	Play();
}

LoadedLevel::~LoadedLevel()
{
}
