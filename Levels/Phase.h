#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include "../Lists/EntityList.h"
#include "../Managers/CollisionManager.h"
#include "../Entities/Platform.h"
#include "../Entities/SpikeBall.h"
#include "../Entities/SpikeWall.h"
#include "../Entities/Portal.h"
#include "../Entities/Player1.h"
#include "../Entities/Player2.h"
#include "../Enemies/Wizard.h"
#include "../Enemies/Bat.h"
#include "../Enemies/Boss.h"
#include "../Memento/MainMemento.h"
#include <Windows.h>
#include <stack>
using namespace std;
class Phase:public Entity
{
private:
	stack<Platform*>stack;
	float newbatCount;
	string savefile;
public:
	void CreatePlayer1(float positionX, float positionY);
	void CreatePlayer2(float positionX, float positionY, bool playable);
	void CreatePlatform(float positionX, float positionY);
	void CreateWizard(float positionX, float positionY, float initialX);
	void CreateBat(float positionX, float positionY);
	void CreateSpikeBall(float positionX, float positionY, float initialY);
	void CreateSpikeWall(float positionX, float positionY);
	void CreatePortal(float positionX, float positionY);
	void CreateBoss(float positionX, float positionY);
	void loadState();
	string getPhaseToLoad();
	void pauseGame();
public:
	Phase();
	~Phase();
	void Play();
	Player1* getPlayer1() { return this->player1; }
	Player2* getPlayer2() { return this->player2; }
	void saveState(string phaseToSave);
	string getPhaseName() { return this->phaseName; };
protected:
	Player1* player1;
	Player2* player2;
	string phaseName;
	virtual void Update() {}
	void GenerateBoss();
	void GenerateBats();
	void GenerateObstaclesAndWizards();
	void GeneratePlatforms();
	void GeneratePlayer1();
	void GeneratePlayer2(bool playable);
};


