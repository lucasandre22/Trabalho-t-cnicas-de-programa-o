#include "GraphicManager.h"
#include <Windows.h>
#include <time.h>
np_GraphicManager::GraphicManager * np_GraphicManager::GraphicManager::instance = 0;
float::np_GraphicManager::GraphicManager::time = 30.0f;
np_GraphicManager::GraphicManager::GraphicManager() :
	window(sf::VideoMode(1366, 768), "Nameless", sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize),
	view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(1920, 1080)) {
	this->font.loadFromFile("Dreamwalker.TTF");
	this->text.setFont(font);
	this->text.setFillColor(sf::Color::White);
	this->texture.loadFromFile(MENUBACKGROUND);
	this->deltaTime = 0.0f;
	this->view.setCenter(-1500.0f, 300.0f);
	this->window.setView(this->view);
	this->menusprite.setTexture(texture);
	this->menusprite.setOrigin(960.0f, 540.0f);
	this->menusprite.setPosition(this->getViewCenterX(), this->getViewCenterY());

}

np_GraphicManager::GraphicManager::~GraphicManager()
{
}

np_GraphicManager::GraphicManager* np_GraphicManager::GraphicManager::getInstance() {
	if (instance == 0) {
		instance = new GraphicManager;
	}
	return instance;
}

void np_GraphicManager::GraphicManager::Draw(int id) {
	window.draw(textures.getBody(id));
}

bool np_GraphicManager::GraphicManager::OpenWindow() {
	sf::Event event;
	if (window.isOpen()) {
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::Resized:
				break;
			}
		}
		return true;
	}
	return false;
}

void np_GraphicManager::GraphicManager::AdjustView(float PositionX) {
	view.setCenter(PositionX, 300.0f);
	window.setView(view);
	window.display();
}

void np_GraphicManager::GraphicManager::Time() {
	deltaTime = clock.restart().asSeconds();
	if (deltaTime > 1.0f / 20.0f) {
		deltaTime = 1.0f / 20.0f;
	}
}

void np_GraphicManager::GraphicManager::Update(int id, float x, float y, int row, bool faceRight) {
	textures.Update(id, x, y, row, deltaTime, faceRight);
}

void np_GraphicManager::GraphicManager::InitializeBody(int id, float x, float y, float sizeX, float sizeY) {
	sf::RectangleShape& body = textures.getBody(id);
	body.setSize(sf::Vector2f(sizeX, sizeY));
	body.setOrigin(body.getSize() / 2.0f);
	body.setPosition(x, y);
}

const int np_GraphicManager::GraphicManager::generateID(string textureName) {
	sf::Texture* tx = new sf::Texture;
	sf::Vector2u imageCount(5,3);
	try {
		if (textureName.compare("background") == 0) {
			tx->loadFromFile(BACKGROUND);
		}
		else if (textureName.compare("background2") == 0) {
			tx->loadFromFile(BACKGROUND2);
		}
		else if (textureName.compare("background3") == 0) {
			tx->loadFromFile(BACKGROUND3);
		}
		else if (textureName.compare("projectile1") == 0) {
			tx->loadFromFile(PROJECTILE1);
		}
		else if (textureName.compare("projectile2") == 0) {
			tx->loadFromFile(PROJECTILE2);
		}
		else if (textureName.compare("projectile3") == 0) {
			tx->loadFromFile(PROJECTILE3);
		}
		else if (textureName.compare("platform") == 0) {
			tx->loadFromFile(PLATFORM);
		}
		else if (textureName.compare("spikeball") == 0) {
			tx->loadFromFile(SPIKEBALL);
		}
		else if (textureName.compare("spikewall") == 0) {
			tx->loadFromFile(SPIKEWALL);
		}
		else if (textureName.compare("portal") == 0) {
			tx->loadFromFile(PORTAL);
		}
		else if (textureName.compare("player1") == 0) {
			tx->loadFromFile(PLAYER1);
		}
		else if (textureName.compare("bat") == 0) {
			tx->loadFromFile(BAT);
		}
		else if (textureName.compare("boss") == 0) {
			tx->loadFromFile(BOSS);
			imageCount.x = 8;
		}
		else if (textureName.compare("wizardGreen") == 0) {
			tx->loadFromFile(WIZARDGREEN);
		}
		else if (textureName.compare("wizardRed") == 0) {
			tx->loadFromFile(WIZARDRED);
		}
		else if (textureName.compare("projectile4") == 0) {
			tx->loadFromFile(PROJECTILE4);
		}
		else if (textureName.compare("player2") == 0) {
			tx->loadFromFile(PLAYER2);
		}
		else throw 1315;
	}
	catch (int warning) {
		if (warning == 1315) {
			cerr << "Erro ao carregar imagem" << endl;
			exit(1315);
		}
	}
	return textures.IncludeTexture(tx, imageCount);
}

void np_GraphicManager::GraphicManager::HighlightOption(string text) {
	for (int i = 0; i < MenuOptions.size(); i++) {
		MenuOptions[i].setCharacterSize(100);
		if (text.compare(MenuOptions[i].getString()) == 0) {
			MenuOptions[i].setFillColor(sf::Color::Black);
		}
		else {
			MenuOptions[i].setFillColor(sf::Color::White);
		}
	}
}

void np_GraphicManager::GraphicManager::setOption(string text, float x, float y) {
	MenuOptions.push_back(sf::Text(text, font));
	MenuOptions.back().setPosition(x, y);
}

int np_GraphicManager::GraphicManager::OptionSelected() {
	sf::Event event;
	while (window.pollEvent(event)) {
		switch (event.type) {
		case sf::Event::KeyReleased:
			switch (event.key.code) {
			case sf::Keyboard::Up:
				return 1;
			case sf::Keyboard::Down:
				return 2;
			case sf::Keyboard::Return:
				return 3;
			}
		}
	}
}

void np_GraphicManager::GraphicManager::DrawMenu() {
	for (int i = 0; i < MenuOptions.size(); i++) {
		window.draw(MenuOptions[i]);
	}
	window.display();
}

void np_GraphicManager::GraphicManager::DrawMenuSprite() {
	window.draw(this->menusprite);
}

void np_GraphicManager::GraphicManager::clearMenu() {
	MenuOptions.clear();
}

void np_GraphicManager::GraphicManager::DisplayScore(unsigned int score) {
	string string = "Score: ";
	string += to_string(score);
	this->text.setPosition(view.getCenter().x - 40.0f, view.getCenter().y - view.getSize().y / 2.0f);
	this->text.setString(string);
	this->window.draw(text);
}

void np_GraphicManager::GraphicManager::DisplayTime() {
	string seconds = "Time: ";
	sf::Text t;
	t.setFont(font);
	time -= this->deltaTime;
	seconds += to_string(time);
	t.setPosition(view.getCenter().x - 300.0f, view.getCenter().y - view.getSize().y / 2.0f);
	t.setString(seconds);
	this->window.draw(t);
}