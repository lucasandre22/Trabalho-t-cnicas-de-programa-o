#pragma once
#include "../Levels/PhaseOne.h"
#include "../Levels/PhaseTwo.h"
#include "../Managers/GraphicManager.h"
#include "../Menus/Menu.h"

#include <string>
#include <vector>
#include <queue>
#include <iostream>
#include <fstream>

using namespace std;

class MainMenu : public Menu
{
public:
	MainMenu();
	~MainMenu();
	const int Selected();
	void InitializeGameOptions();
	void PlayersOptions();
	void ScoreMenu();
	void ShowRanking(string s[5]);
	void WinScreen();
	void GameOverScreen();
};