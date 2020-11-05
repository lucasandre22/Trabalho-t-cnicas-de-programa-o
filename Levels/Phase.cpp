#include "Phase.h"

#define START_POSITIONX -1500.0f
#define START_POSITIONY 300.0f
#define RIGHT_BORDER 1800.0f
Phase::Phase() :
	Entity() {
	this->collider->Clear();
	this->newbatCount = 5.0f;
	this->player1 = nullptr;
	this->player2 = nullptr;
	this->savefile = "save.txt";
}

Phase::~Phase()
{
}

void Phase::Play() {
	while (this->window->OpenWindow()) {
		if (this->player1->getAlive() && GraphicManager::time > 0.0f) {
			if (this->window->S()) {
				saveState(this->getPhaseName());
			}
			if (this->window->P()){
				pauseGame();
			}
			this->enlist->Update();
			this->enlist->Draw();
			this->collider->Collided();
			GenerateBats();
			this->window->DisplayTime();
			this->window->DisplayScore(Player1::score);
			this->window->Time();
			this->window->AdjustView(player1->getPositionX());
			this->window->ClearWindow();
		}
		else {
			this->window->ClearWindow();
			this->window->AdjustView(-1500.0f);
			return;
		}
	}
}

void Phase::CreatePlatform(float positionX, float positionY) {
	Platform* platform = new Platform(positionX, positionY, 160.0f, 30.0f);
	stack.push(platform);
}

void Phase::CreatePlayer1(float positionX, float positionY) {
	Player1* player1 = new Player1(positionX, positionY, 50.0f, 50.0f);
	this->player1 = player1;
}

void Phase::CreatePlayer2(float positionX, float positionY, bool playable) {
	Player2* player2 = new Player2(positionX, positionY - 600.0f, 35.0f, 35.0f, playable);
	this->player2 = player2;
	this->player2->setPlayer1(this->player1);
}

void Phase::CreateWizard(float positionX, float positionY, float initialX) {
	Wizard* wizard = new Wizard(positionX, positionY, 72.0f, 48.0f, initialX);
	wizard->setPlayer1(this->player1);
	wizard->setPlayer2(this->player2);
}

void Phase::CreateBat(float positionX, float positionY) {
	Bat* bat = new Bat(positionX, positionY, 60.0f, 60.0f);
}

void Phase::CreateSpikeBall(float positionX, float positionY, float initialY){
	SpikeBall* spikeBall = new SpikeBall(positionX, positionY, 25.0f, 25.0f, initialY);
}

void Phase::CreateSpikeWall(float positionX, float positionY){
	SpikeWall* spikeWall = new SpikeWall(positionX, positionY, 40.0f, 110.0f);
}

void Phase::CreatePortal(float positionX, float positionY){
	Portal* portal = new Portal(positionX, positionY, 110.0f, 25.0f);
	portal->setPlayer1(this->player1);
}

void Phase::CreateBoss(float positionX, float positionY) {
	Boss* boss = new Boss(positionX, positionY, 250.0f, 250.0f);
	boss->setPlayer1(this->player1);
	boss->setPlayer2(this->player2);
}

void Phase::saveState(string phaseToSave){
	std::ofstream file(this->savefile);
	MainMemento memento;
	file << phaseToSave << '\n';
	file << GraphicManager::time << '\n';
	memento.savePlayer(this->player1, this->player2);
	for (auto& i : this->collider->getPairVector()) {
		memento.saveEntities(i);
	}
	memento.saveToFile(file);
}

void Phase::GenerateBoss() {
	CreateBoss(-2500.0f, 350.0f);
}

void Phase::GenerateBats() {
	this->newbatCount += window->getDeltaTime();
	if (this->newbatCount > 5.5f) {
		CreateBat(2500.0f, this->player1->getPositionY());
		this->newbatCount = 0.0f;
	}
}

void Phase::GeneratePlatforms() {
	float x = START_POSITIONX + 350.0f;
	float y = START_POSITIONY;
	CreatePlatform(START_POSITIONX, START_POSITIONY);
	srand(static_cast<unsigned int>(time(nullptr)));
	for (x; x < RIGHT_BORDER; x += 350.0f) {
		CreatePlatform(x, y);
		if (rand() % 2 == 0) {
			CreatePlatform(stack.top()->getPositionX() + 175.0f, stack.top()->getPositionY() - 150.0f);
			CreatePlatform(stack.top()->getPositionX(), stack.top()->getPositionY() - 150.0f);
		}
		else {
			CreatePlatform(stack.top()->getPositionX(), stack.top()->getPositionY() - 150.0f);
		}
		CreatePlatform(x, y + 300.0f);
		if (rand() % 2 == 0) {
			CreatePlatform(stack.top()->getPositionX() + 175.0f, stack.top()->getPositionY() - 150.0f);
			CreatePlatform(stack.top()->getPositionX(), stack.top()->getPositionY() - 150.0f);
		}
		else {
			CreatePlatform(stack.top()->getPositionX(), stack.top()->getPositionY() - 150.0f);
		}
	}
}

void Phase::GenerateObstaclesAndWizards() {
	int random;
	while(stack.size() != 0) {
		random = rand() % 6;
		if (random < 2) {
			CreateWizard(stack.top()->getPositionX(), stack.top()->getPositionY() - 40.0f, stack.top()->getPositionX());
		}
		else if (random == 3) {
			CreateSpikeBall(stack.top()->getPositionX(), stack.top()->getPositionY() - 80.0f, stack.top()->getPositionY() - 80.0f);
		}
		else if (random == 4) {
			CreatePortal(stack.top()->getPositionX(), stack.top()->getPositionY() - 20.0f);
		}
		else if (random == 5) {
			CreateSpikeWall(stack.top()->getPositionX() + 87.0f, stack.top()->getPositionY() - 65.0f);
		}
		stack.pop();
		//Evita a primeira plataforma
		if (stack.size() == 1) {
			stack.pop();
		}
	}
}

void Phase::GeneratePlayer1() {
	CreatePlayer1(START_POSITIONX, START_POSITIONY - 100.0f);
}

void Phase::GeneratePlayer2(bool playable) {
	CreatePlayer2(START_POSITIONX, START_POSITIONY - 100.0f, playable);
}

void Phase::loadState()
{
	std::ifstream file("save.txt");
	if (file) {
		//ignora linha que esta escrito o level
		file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		file >> GraphicManager::time;
		MainMemento memento = MainMemento::loadFromFile(file);
		CreatePlayer1(0.0f, 0.0f);
		this->player1->loadMemento(memento.getpl1memento());
		if (memento.getpl2memento()->getPositionY() == -400.0f) {
			CreatePlayer2(0.0f, 0.0f, false);
		}
		else {
			CreatePlayer2(0.0f, 0.0f, true);
		}
		this->player2->loadMemento(memento.getpl2memento());
		this->player2->setPlayer1(this->player1);
		for (std::pair<std::string, Memento*> i : memento.getEntitiesMemento()) {
			if (i.first == "Platform") {
				Platform* platform = new Platform();
				platform->loadMemento(static_cast<PlatformMemento*>(i.second));
			}
			else if (i.first == "Wizard") {
				Wizard* wizard = new Wizard();
				wizard->loadMemento(static_cast<WizardMemento*>(i.second));
				wizard->setPlayer1(this->player1);
				wizard->setPlayer2(this->player2);
			}
			else if (i.first == "Boss") {
				Boss* boss = new Boss();
				boss->loadMemento(static_cast<BossMemento*>(i.second));
				boss->setPlayer1(this->player1);
				boss->setPlayer2(this->player2);
			}
			else if (i.first == "SpikeWall") {
				SpikeWall* spikewall = new SpikeWall();
				spikewall->loadMemento(static_cast<SpikeWallMemento*>(i.second));
			}
			else if (i.first == "SpikeBall") {
				SpikeBall* spikeball = new SpikeBall();
				spikeball->loadMemento(static_cast<SpikeBallMemento*>(i.second));
			}
			else if (i.first == "Portal") {
				Portal* portal = new Portal();
				portal->loadMemento(static_cast<PortalMemento*>(i.second));
				portal->setPlayer1(this->player1);
			}
		}
		file.close();
	}
}

string Phase::getPhaseToLoad(){
	string phaseToLoad;
	std::ifstream file("save.txt");
	if (file) {
		file >> phaseToLoad;
	}
	file.close();
	return phaseToLoad;
}

void Phase::pauseGame(){
	while (!window->ESC()) {}
	return;
}