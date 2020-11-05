#include "Memento.h"
#include "../Entities/Player1.h"
#include "../Entities/Player2.h"
#include "../Enemies/Wizard.h"
#include "../Entities/Platform.h"
#include "../Entities/SpikeWall.h"
#include "../Entities/Portal.h"
#include "../Entities/SpikeBall.h"
#include "../Enemies/Boss.h"
#include "Player1Memento.h"
#include "Player2Memento.h"
#include "WizardMemento.h"
#include "PlatformMemento.h"
#include "SpikeWallMemento.h"
#include "SpikeBallMemento.h"
#include "PortalMemento.h"
#include "BossMemento.h"
#include <vector>
#include <utility>
#pragma once
class MainMemento : public Memento
{
public:
	MainMemento();
	~MainMemento();
	void saveToFile(std::ostream& file) override;
	static MainMemento loadFromFile(std::istream& file);
	void savePlayer(Player1* player1, Player2* player2);
	void saveEntities(Entity* e);
	Player1Memento* player1memento;
	Player2Memento* player2memento;
	Player1Memento* getpl1memento() { return this->player1memento; };
	Player2Memento* getpl2memento() { return this->player2memento; }
	std::vector<std::pair<std::string, Memento*>> entitiesmemento;
	const std::vector<std::pair<std::string, Memento*>> getEntitiesMemento() { return this->entitiesmemento; }
};

