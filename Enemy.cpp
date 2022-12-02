#include "Enemy.h"

Enemy::Enemy(int enemy)
{
	std::ifstream f("./Enemy/enemy_monekoup.json");
	this->data = json::parse(f);

	this->name = this->data["pokemon"][enemy]["name"];
	this->Pv = (int)(this->data["pokemon"][enemy]["pv"]);
	this->vitesse = (int)(this->data["pokemon"][enemy]["vitesse"]);
	this->path = this->data["pokemon"][enemy]["path"];

	this->enemy_texture.loadFromFile(this->path);
	this->enemy_sprite.setTexture(enemy_texture);
	this->enemy_sprite.setPosition(this->pos_x, this->pos_y);
	this->enemySheetPos = sf::Vector2i(0, 1);

}

Enemy::~Enemy()
{
}

int Enemy::showPv() {
	return this->Pv;
}

void Enemy::pv(int atk)
{
	this->Pv = this->Pv - atk;
	if (this->Pv <= 0) {
		this->is_alive = false;
	}
}

void Enemy::reset() {
	this->dir = 0;
	this->pos_x = 360;
	this->pos_y = 745;
	setPosition(pos_x, pos_y);
}

void Enemy::setAnimRect()
{
	this->enemy_sprite.setTextureRect(sf::IntRect(enemySheetPos.x * ENEMY_SIZE, enemySheetPos.y * ENEMY_SIZE, ENEMY_SIZE, ENEMY_SIZE));
	if (enemyClock.getElapsedTime().asSeconds()>0.2f)
	{
		enemySheetPos.x++;
		if (enemySheetPos.x == 3)
		{
			enemySheetPos.x = 0;
		}
		enemyClock.restart();
	}
}

const sf::Sprite Enemy::getSprite() {
	return this->enemy_sprite;
}

int Enemy::return_pos()
{
	return (this->pos_x, this->pos_y);
}

void Enemy::setPosition(int x, int y) 
{
	this->pos_x = x;
	this->pos_y = y;
	this->enemy_sprite.setPosition(x, y);
	this->dir = Right;
}

void Enemy::deplacement()
{
	this->pos_x = enemy_sprite.getPosition().x;
	this->pos_y = enemy_sprite.getPosition().y;

	if (dir == Right){
		enemy_sprite.move(0.02f, 0);
		enemySheetPos.y = Right;
		if (this->pos_x == 670){
			this->dir = Up;
		}
		else if (this->pos_x == 910) {
			this->dir = Down;
		}
	}
	
	if (this->dir == Up){
		enemy_sprite.move(0,-0.02f);
		enemySheetPos.y = Up;
		if (this->pos_y == 220) {
			this->dir = Right;
		}
	}
	if (this->dir == Down) {
		enemy_sprite.move(0, 0.02f);

		enemySheetPos.y = Down;
	}
}

int Enemy::nbr_checpoint()
{
	return this->checkpoint;
}

bool Enemy::return_is_alive()
{
	return this->is_alive;
}

sf::Vector2f Enemy::GetPosition()
{	
	enemyCoords.x = enemy_sprite.getPosition().x;
	enemyCoords.y = enemy_sprite.getPosition().y;
	return enemyCoords;
}

sf::FloatRect Enemy::GetHitBox() {
	sf::RectangleShape enemyHitBoxSize(sf::Vector2f(100, 100));
	
	return enemyHitBox = enemyHitBoxSize.getGlobalBounds();
}