#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>

#include "Gui.h"

#pragma once

class Window
{
public:
	//Construtor & Destructor 
	Window();
	~Window();
	//Prepare elements to display 
	void displayMenu();
	void displaySettings();
	void displayMap();
	//Clear button
	void openPauseMenu();
	void closePauseMenu();
	//Debug
	void test(int id, int x, int y);
	//Define construction area of tower
	void buildArea();

	std::map<std::string, gui::Rect*> rectList;
	std::map<std::string, gui::Button*> buttonList;
	std::map<std::string, gui::Image*> imageList;
	std::map<std::string, gui::Map*> mapList;

	std::map<std::string, gui::Button*> pauseButtonList;
	std::map<std::string, gui::Rect*> pauseRectList;

	std::map<std::string, gui::Rect*> towerList;
	std::map<std::string, gui::Button*> buildAreaList;

	sf::Vector2i mousePos;

private:

};
