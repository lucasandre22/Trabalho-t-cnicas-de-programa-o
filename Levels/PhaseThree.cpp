#include "PhaseThree.h"

PhaseThree::PhaseThree(bool playertwo, bool loading) :
	Phase()
{
	this->collider->Clear();
	this->id = window->generateID("background3");
	this->positionX = 0.0f;
	this->positionY = 290.0f;
	this->sizeX = 6000.0f;
	this->sizeY = 1200.0f;
	window->InitializeBody(id, positionX, positionY, sizeX, sizeY);
	this->phaseName = "levelthree";
	GraphicManager::time = 5.0f;
	if (!loading)
	{
		GeneratePlayer1();
		GeneratePlayer2(playertwo);
		GenerateBoss();
		GeneratePlatforms();
	}
	else
		loadState();
	Play();
}

PhaseThree::~PhaseThree()
{
	enlist->Remove(this);
}



