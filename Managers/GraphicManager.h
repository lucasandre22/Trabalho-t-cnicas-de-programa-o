#pragma once
#define BACKGROUND "background.png"
#define BACKGROUND2 "background2.jpg"
#define BACKGROUND3 "background3.png"
#define MENUBACKGROUND "menubackground.jpg"
#define PROJECTILE1 "projectile1.png"
#define PROJECTILE2 "projectile2.png"
#define PROJECTILE3 "projectile3.png"
#define PROJECTILE4 "projectile4.png"
#define PLAYER1 "player1.png"
#define PLAYER2 "player2.png"
#define PLATFORM "platform.png"
#define SPIKEBALL "spikeball.png"
#define SPIKEWALL "spikewall.png"
#define PORTAL "portal.png"
#define WIZARDRED "wizardRed.png"
#define WIZARDGREEN "wizardGreen.png"
#define BAT "bat.png"
#define BOSS "boss.png"

#include "SFML/Graphics.hpp"
#include "../Animation/TextureMap.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
using namespace np_TextureMap;
namespace np_GraphicManager {
	class GraphicManager
	{
	private:
		GraphicManager();
		static GraphicManager* instance;
		np_TextureMap::TextureMap textures;
		sf::RenderWindow window;
		sf::View view;
		sf::Clock clock;
		sf::Font font;
		sf::Text text;
		sf::Sprite menusprite;
		sf::Texture texture;
		vector<sf::Text> MenuOptions;
		float deltaTime;

	public:
		static GraphicManager* getInstance();
		~GraphicManager();
		void Draw(int id);
		void Update(int id, float x, float y, int row, bool faceRight);
		void InitializeBody(int id, float x, float y, float sizeX, float sizeY);
		void AdjustView(float PositionX);
		void Time();
		void CloseWindow() { window.close(); }
		void ClearWindow() { window.clear(sf::Color(150, 150, 150)); }
		void HighlightOption(string text);
		void setOption(string text, float x, float y);
		void DisplayScore(unsigned int score);
		void DisplayTime();
		void DrawMenu();
		void DrawMenuSprite();
		void clearMenu();
		const float getDeltaTime() { return deltaTime; }
		const int generateID(string className);
		bool OpenWindow();
		int OptionSelected();
		const bool A() { return sf::Keyboard::isKeyPressed(sf::Keyboard::A); }
		const bool S() { return sf::Keyboard::isKeyPressed(sf::Keyboard::S); }
		const bool W() { return sf::Keyboard::isKeyPressed(sf::Keyboard::W); }
		const bool D() { return sf::Keyboard::isKeyPressed(sf::Keyboard::D); }
		const bool SPACE() { return sf::Keyboard::isKeyPressed(sf::Keyboard::Space); }
		const bool UP() { return sf::Keyboard::isKeyPressed(sf::Keyboard::Up); }
		const bool DOWN() { return sf::Keyboard::isKeyPressed(sf::Keyboard::Down); }
		const bool RIGHT() { return sf::Keyboard::isKeyPressed(sf::Keyboard::Right); }
		const bool LEFT() { return sf::Keyboard::isKeyPressed(sf::Keyboard::Left); }
		const bool RSHIFT() { return sf::Keyboard::isKeyPressed(sf::Keyboard::RShift); }
		const bool P() { return sf::Keyboard::isKeyPressed(sf::Keyboard::P); }
		const bool ESC() { return sf::Keyboard::isKeyPressed(sf::Keyboard::Escape); }
		const size_t getWindowSizeY() { return window.getSize().y; }
		const size_t getWindowSizeX() { return window.getSize().x; }
		const float getViewCenterX() { return view.getCenter().x; }
		const float getViewCenterY() { return view.getCenter().y; }
		static float time;
	};
}