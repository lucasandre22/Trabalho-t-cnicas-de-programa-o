#include "MainMenu.h"

MainMenu::MainMenu() :
	Menu()
{
}

MainMenu::~MainMenu()
{
}

const int MainMenu::Selected(){
	int i = 1;
	while (chosen != options.begin()){
		chosen--;
		i++;
	}
	return i;
}

void MainMenu::InitializeGameOptions()
{
	options.clear();
	options.push_back("RETURN");
	options.push_back("LOAD LEVEL");
	options.push_back("LEVEL ONE");
	options.push_back("LEVEL TWO");
	options.push_back("LEVEL THREE");
}

void MainMenu::PlayersOptions()
{
	options.clear();
	options.push_back("ONE PLAYER");
	options.push_back("TWO PLAYERS");
	options.push_back("RANKING");
	options.push_back("EXIT");
}


void MainMenu::ScoreMenu()
{
	options.clear();
	options.push_back("SAVE SCORE");
	options.push_back("RETURN");
}

void MainMenu::ShowRanking(string s[5]){
	options.clear();
	for (int i = 0; i < 5; i++){
		options.push_back(s[i]);
	}
}


void MainMenu::WinScreen(){
	string score;
	options.clear();
	score = "YOU WON!\nSCORE: ";
	score += to_string(Player1::score);
	options.push_back(score);
}

void MainMenu::GameOverScreen(){
	string score;
	options.clear();
	score = "TRY AGAIN!\nSCORE: ";
	score += to_string(Player1::score);
	options.push_back(score);
}
