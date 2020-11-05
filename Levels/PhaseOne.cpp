#include "PhaseOne.h"
PhaseOne::PhaseOne(bool playertwo, bool loading) :
	Phase()
{
	this->id = window->generateID("background");
	this->positionX = 0.0f;
	this->positionY = 290.0f;
	this->sizeX = 6000.0f;
	this->sizeY = 1200.0f;
	window->InitializeBody(id, positionX, positionY, sizeX, sizeY);
	this->phaseName = "levelone";
	GraphicManager::time = 30.0f;
	if (!loading) {
		GeneratePlayer1();
		GeneratePlayer2(playertwo);
		GeneratePlatforms();
		GenerateObstaclesAndWizards();
	}
	else {
		loadState();
	}
	Play();
}

PhaseOne::~PhaseOne()
{
	enlist->Remove(this);
}

