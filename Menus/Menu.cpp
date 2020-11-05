#include "Menu.h"

Menu::Menu()
{
	this->window = GraphicManager::getInstance();
}

Menu::~Menu()
{
}

void Menu::setMenuOptions()
{
	window->clearMenu();
	for (int i = 0; i < options.size(); i++) {
		window->setOption(options[i], (window->getViewCenterX() - 200.0f), window->getViewCenterY() - 100.0f + (100.0f * i));
	}
	chosen = options.begin();
	if (!options.empty()){
		window->HighlightOption(*chosen);
	}
}

void Menu::setRanking(){
	window->clearMenu();
	for (int i = 0; i < rank.size(); i++) {
		window->setOption(rank[i], (window->getViewCenterX() - 200.0f), window->getViewCenterY() - 300.0f + (100.0f * i));
	}
}

void Menu::MoveUp(){
	if (chosen != options.begin()) {
		chosen--;
	}
	window->HighlightOption(*chosen);
}

void Menu::MoveDown(){
	if (chosen != --options.end()) {
		chosen++;
	}
	window->HighlightOption(*chosen);
}

int Menu::Execute()
{
	setMenuOptions();
	while (window->OpenWindow())
	{
		window->DrawMenuSprite();
		window->DrawMenu();
		switch (window->OptionSelected())
		{
		case 1:
			MoveUp();
			break;
		case 2:
			MoveDown();
			break;
		case 3:
			return Selected();
			break;
		}
	}
}