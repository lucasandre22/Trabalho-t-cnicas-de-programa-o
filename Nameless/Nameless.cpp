#include "Nameless.h"
#include <sstream>

Nameless::Nameless(){
	this->window = GraphicManager::getInstance(); 
	this->enlist = EntityList::getInstance();
	this->collider = CollisionManager::getInstance();
	this->playertwo = false; 
	this->phase = nullptr;
	this->loading = false;
}

void Nameless::MainMenu() {
	Player1::score = 0;
	this->loading = false;
	while (true) {
		Menu.InitializeGameOptions();
		switch (Menu.Execute()) {
		case 1:
			Players();
			break;
		case 2:
			LoadGame();
			break;
		case 3:
			pile.push(PhaseOne(this->playertwo, this->loading));
			if (GameOver()) { LoseScreen(); break; }
		case 4:
			pile.push(PhaseTwo(this->playertwo, this->loading));
			if (GameOver()) { LoseScreen(); break; }
		case 5:
			pile.push(PhaseThree(this->playertwo, this->loading));
			if (GraphicManager::time <= 0.1f) { WinScreen(); break; }
			else if (GameOver()) { LoseScreen(); break; }
		}
	}
}

void Nameless::LoadGame() {

	this->loading = true;
	string phasename = phase->getPhaseToLoad();
	if (phasename == "levelone") {
		pile.push(PhaseOne(this->playertwo, this->loading));
		this->loading = false;
		if (GameOver()){ 
			LoseScreen(); 
			return;
		}
	}
	if (phasename == "leveltwo" || phasename == "levelone") {
		pile.push(PhaseTwo(this->playertwo, this->loading));
		this->loading = false;
		if (GameOver()) { 
			LoseScreen(); 
			return;
		}
	}
	pile.push(PhaseThree(this->playertwo, this->loading));
	if (GraphicManager::time <= 0.1f) { WinScreen(); }
	else if (GameOver()) { LoseScreen(); }
	this->loading = false;
}

void Nameless::Players(){
	Menu.PlayersOptions();
	switch (Menu.Execute())
	{
	case 1:
		playertwo = false;
		MainMenu();
		break;
	case 2:
		playertwo = true;
		MainMenu();
		break;
	case 3:
		Ranking();
	case 4:
		window->CloseWindow();
		break;
	}
}


bool Nameless::GameOver() {
	return (!pile.top().getPlayer1()->getAlive());
}

bool Nameless::Win(){
	return (GraphicManager::time < 0.1f);
}

void Nameless::SaveScore()
{
	string scoreRecorded;
	string nameAndScore;
	string nameAux;
	bool alreadySave = false;
	//são salvos apenas 5 scores no arquivo
	//há 6 posições porque uma é usada para comparar o score atual com os ja armazenados
	int scoresRecorded[6];
	int numberofscores = 0;
	std::queue<std::string> ranking;
	ifstream arquive("ranking.txt", ios::in);
	//insere o nome e o score na variável nameAndScore
	nameAndScore = to_string(Player1::score);
	nameAndScore.push_back('.');
	cout << "Name: " << endl;
	cin >> nameAux;
	nameAndScore += nameAux;
	//armazena o novo score na última posição do vetor
	scoresRecorded[5] = stoi(nameAndScore); 
	while (getline(arquive, scoreRecorded) && numberofscores < 5){
		//recupera os scores salvos no arquivo
		scoresRecorded[numberofscores++] = atoi(scoreRecorded.c_str()); 
		//armazena na fila
		ranking.push(scoreRecorded);
	}
	arquive.close();
	ofstream save("ranking.txt", ios::out);
	for (unsigned int i = 0; i < 5 && !ranking.empty(); i++) {
		//compara os valores armazenados com o novo
		if (scoresRecorded[i] < scoresRecorded[5] && !alreadySave){
			save << nameAndScore << std::endl;
			alreadySave = true;
		}
		else{
			save << ranking.front() << std::endl;
			ranking.pop();
		}
	}
	if (!alreadySave && numberofscores < 5) {
		save << nameAndScore << endl;
	}
	save.close();
}

void Nameless::Ranking(){
	string ranking[5];
	ifstream arquive("ranking.txt", ios::in);
	for (int i = 0; i < 5; i++) {
		if (!arquive.fail()) {
			arquive >> ranking[i];
		}
		else {
			ranking[i] = -1;
		}
	}
	arquive.close();
	Menu.ShowRanking(ranking);
	switch (Menu.Execute()) {
	case 1:
		Players();
		break;
	}
}

void Nameless::WinScreen(){	
	Menu.WinScreen();
	switch (Menu.Execute()) {
	case 1:
		SaveScore();
		break;
	}
}

void Nameless::LoseScreen(){
	Menu.GameOverScreen();
	switch (Menu.Execute()) {
	case 1:
		SaveScore();
		break;
	}
}
