#pragma once
#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

#include "Gui.h"

using json = nlohmann::json;

//#include"liste_ennemy.cpp"

#include"string"
class Enemy
{
protected:

	std::string name;
	json data;
	json collision;

	sf::Sprite enemy_sprite;
	sf::Texture enemy_texture;
	sf::Vector2i enemySheetPos;
	sf::Clock enemyClock;

	sf::Vector2f enemyCoords;

	int intersection;
	int checkpoint = 0;
	int Pv;
	int vitesse;
	int dir = Right;

	int pos_affichage;
	bool is_alive = true;
	std::string path;
	int animPosX = 0;
	int Wait = 0;


	const int ENEMY_SIZE = 100;
	enum moveDir{Down, Right, Left, Up};

	
	sf::FloatRect enemyHitBox;

public:
	//Construtor & Destructor 
	Enemy(int);
	~Enemy();

	//Some console functions for debug 
	int showPv();
	int nbr_checpoint();
	int return_pos();
	void pv(int atk);
	//Reset enemy position
	void reset();
	//Define animation rect size and animation frequency
	void setAnimRect();
	//Set Enemy position
	void setPosition(int x, int y);
	//Move the enemy sprite
	void deplacement();

	//Getter
	sf::FloatRect GetHitBox();
	sf::Vector2f GetPosition();
	const sf::Sprite getSprite();
	bool return_is_alive();

	//Enemy initial position 
	int pos_x = 0;
	int pos_y = 0;
};
