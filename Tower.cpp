#include "Tower.h"

Tower::Tower()
{
}

Tower::~Tower()
{
}

void Tower::newTower(int id, int x, int y) {
		this->towerList[std::to_string(id)] = new gui::Tower("./Tower/Pika.png", x - 20, y - 30);
		this->id = id;
		this->damage = 1;
}

sf::FloatRect Tower::GetTowerHitArea()
{
	sf::RectangleShape towerRangeSize(sf::Vector2f(500, 500));
	return sf::FloatRect() = towerRangeSize.getGlobalBounds();
}

void Tower::SetSpriteTexture()
{
	sf::Texture atkSprite_texture;
	atkSprite_texture.loadFromFile("./Tower/atack.png");
	atkSprite.setTexture(atkSprite_texture);
}

void Tower::SetAtkSpritePos(sf::Vector2f enemyCoords)
{
	atkSprite.setPosition(enemyCoords.x, enemyCoords.y);
}


void Tower::RenderATK(sf::RenderWindow& window)
{
	window.draw(atkSprite);
}



