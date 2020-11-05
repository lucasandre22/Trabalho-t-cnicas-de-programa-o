#include "MainMemento.h"

MainMemento::MainMemento(){
	this->player1memento = nullptr;
	this->player2memento = nullptr;
}

MainMemento::~MainMemento()
{
}

void MainMemento::saveToFile(std::ostream& file){
	player1memento->saveToFile(file);
	player2memento->saveToFile(file);
	file << entitiesmemento.size() << ' ' << '\n';
	for (auto& i : entitiesmemento) {
		file << i.first << ' '; // salva type da entidade
		i.second->saveToFile(file);
	}
}

MainMemento MainMemento::loadFromFile(std::istream& file){
	MainMemento memento;
	memento.player1memento = new Player1Memento(Player1Memento::loadFromFile(file));
	memento.player2memento = new Player2Memento(Player2Memento::loadFromFile(file));
	unsigned int mementoSize;
	string type;
	file >> mementoSize;
	for (unsigned int i = 0; i < mementoSize; ++i) {
		file >> type;
		if (type == "Platform") {
		memento.entitiesmemento.emplace_back("Platform", new PlatformMemento(PlatformMemento::loadFromFile(file)));
		}
		else if (type == "Wizard") {
			memento.entitiesmemento.emplace_back("Wizard", new WizardMemento(WizardMemento::loadFromFile(file)));
		}
		else if (type == "Boss") {
			memento.entitiesmemento.emplace_back("Boss", new BossMemento(BossMemento::loadFromFile(file)));
		}
		else if (type == "SpikeWall") {
			memento.entitiesmemento.emplace_back("SpikeWall", new SpikeWallMemento(SpikeWallMemento::loadFromFile(file)));
		}
		else if (type == "SpikeBall") {
			memento.entitiesmemento.emplace_back("SpikeBall", new SpikeBallMemento(SpikeBallMemento::loadFromFile(file)));
		}
		else if (type == "Portal") {
			memento.entitiesmemento.emplace_back("Portal", new PortalMemento(PortalMemento::loadFromFile(file)));
		}
	}
	return memento;
}

void MainMemento::savePlayer(Player1* player1, Player2* player2){
	player1memento = new Player1Memento(player1->createMemento());
	player2memento = new Player2Memento(player2->createMemento());
}

void MainMemento::saveEntities(Entity* e) {
	if (e->getType() == "Wizard") {
		entitiesmemento.emplace_back("Wizard", new WizardMemento(static_cast<Wizard*>(e)->createMemento()));
	}
	else if (e->getType() == "Boss") {
		entitiesmemento.emplace_back("Boss", new BossMemento(static_cast<Boss*>(e)->createMemento()));
	}
	else if (e->getType() == "Platform") {
		entitiesmemento.emplace_back("Platform", new PlatformMemento(static_cast<Platform*>(e)->createMemento()));
	}
	else if (e->getType() == "SpikeWall") {
		entitiesmemento.emplace_back("SpikeWall", new SpikeWallMemento(static_cast<SpikeWall*>(e)->createMemento()));
	}
	else if (e->getType() == "SpikeBall") {
		entitiesmemento.emplace_back("SpikeBall", new SpikeBallMemento(static_cast<SpikeBall*>(e)->createMemento()));
	}
	else if (e->getType() == "Portal") {
		entitiesmemento.emplace_back("Portal", new PortalMemento(static_cast<Portal*>(e)->createMemento()));
	}
}


