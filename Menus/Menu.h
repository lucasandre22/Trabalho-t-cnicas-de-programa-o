#pragma once
#include "../Levels/PhaseOne.h"
#include "../Levels/PhaseTwo.h"
#include "../Managers/GraphicManager.h"

#include <string>
#include <vector>
using namespace std;

class Menu
{
public:
	Menu();
	~Menu();
	void setMenuOptions();
	void setRanking();
	void setChosen(vector<string>::iterator c) { chosen = c; }
	int Execute();
protected:
	vector<string> options;
	vector<string>::iterator chosen;
	vector<string> rank;
	GraphicManager* window;
	virtual const int Selected() = 0;
private:
	void MoveUp();
	void MoveDown();
};