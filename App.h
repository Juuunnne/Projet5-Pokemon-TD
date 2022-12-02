#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>

#include "Window.h"
#include "Gui.h"
#include "Enemy.h"
#include "Tower.h"

#pragma once


class App
{
public:
	//Construtor & Destructor 
	App();
	~App();
	//Main Loop
	void mainLoop(App* app);
	//Render all element
	void render();
	//Check which button was clicked on 
	void isPressed(sf::Event event);

	sf::Vector2i mousePos;
	

private:
	sf::RenderWindow _window;
	sf::Font font;	
	sf::Clock gameClock;

	Tower tower;
	Window myWindow;

	//renderWindow is a index for knowing which element render
	int lastRenderedWindowID = 0;
	int renderWindow = 0;
	int towerId = 0;
	int towerNumber = 0;

	bool pause = false;
	bool isSelected = false;
	bool allowBuild = false;
	
};

