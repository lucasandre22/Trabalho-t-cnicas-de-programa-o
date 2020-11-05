#pragma once
#include "../Levels/Phase.h"
#include "../Levels/PhaseOne.h"
#include "../Levels/PhaseTwo.h"
#include "../Levels/PhaseThree.h"
#include "../Menus/MainMenu.h"
#include "../Managers/GraphicManager.h"
#include <stack>
class Nameless
{
public:
	Nameless();
	~Nameless() {}
	void Players();
private:
	GraphicManager* window;
	EntityList* enlist;
	CollisionManager* collider;
	MainMenu Menu;
	Phase* phase;
	stack<Phase>pile;
	bool playertwo;
	bool loading;
	void MainMenu();
	void LoadGame();
	void Ranking();
	void WinScreen();
	void LoseScreen();
	bool GameOver();
	bool Win();
	void SaveScore();
};