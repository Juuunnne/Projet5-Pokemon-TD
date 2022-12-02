#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <math.h>

#include "Gui.h"

#pragma once

class Tower
{
public:
	//Construtor & Destructor 
	Tower();
	~Tower();
	//Set new tower coords at mouse position
	void newTower(int id, int x, int y);
	//A list that contains all the created tower
	std::map<std::string, gui::Tower*> towerList;
	//Set Tower attack area
	sf::FloatRect GetTowerHitArea();
	//Get attack sprite
	void SetSpriteTexture();
	void SetAtkSpritePos(sf::Vector2f enemyCoords);
	//Draw attack sprite when collided
	void RenderATK(sf::RenderWindow &window);

	int damage;
private:
	int id;
	sf::FloatRect towerRange;
	sf::Sprite atkSprite;
};

