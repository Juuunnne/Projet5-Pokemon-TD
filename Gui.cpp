#include "Gui.h"

Gui::Gui()
{
}

Gui::~Gui()
{
}

gui::Image::Image(std::string imagePath)
{
	// Load a texture from a file
	this->imageLoaded = true;
	if (!texture.loadFromFile(imagePath))
	{
		this->imageLoaded = false;
		std::cout << "ERROR : Image can't be loaded" << std::endl << "Path : " << imagePath << std::endl << std::endl;
	}

	// Assign it to a sprite
	sprite.setTexture(texture);
}

gui::Image::~Image()
{
}

void gui::Image::renderImage(sf::RenderWindow& window) 
{
	window.draw(this->sprite);
}

// Font import Manager
gui::Font::Font(std::string fontPath)
{
	// Load a font from a file
	this->fontLoaded = true;
	if (!this->font.loadFromFile(fontPath))
	{
		this->fontLoaded = false;
		std::cout << "ERROR : Font can't be loaded" << std::endl << "Path : " << fontPath << std::endl << std::endl;
	}
}

gui::Font::~Font()
{
}

// Text Manager with Font Import
gui::Text::Text(std::string fontPath, std::string text, int x, int y, int r, int g, int b) :	Font(fontPath)
{
	if (this->fontLoaded)
	{
		this->text.setFont(this->font);
		this->text.setString(text);
		this->text.setPosition(x, y);
		this->text.setCharacterSize(24); // Rework to change police size
		this->text.setFillColor(sf::Color(r, g, b)); // Rework to change police color with RGB
	}
}

gui::Text::~Text()
{
}

gui::Rect::Rect(std::string fontPath, std::string text, int x, int y, int w, int h, int rr, int rg, int rb, int ra, int cr, int cg, int cb) :	Text(fontPath, text, x, y, cr, cg, cb)
{

	this->rect.setPosition(sf::Vector2f(x, y));
	this->rect.setSize(sf::Vector2f(w, h));
	this->rect.setFillColor(sf::Color(rr,rg,rb,ra));
	
	this->text.setOrigin(round(this->text.getGlobalBounds().width / 2), round(this->text.getGlobalBounds().height / 2));
	this->text.setPosition(x + w / 2, y + h / 2);
	
}

gui::Rect::~Rect()
{
}

// SFML Renderer
void gui::Rect::render(sf::RenderWindow& window)
{
	window.draw(this->rect);
	window.draw(this->text);
}

gui:: Button::Button(int id, std::string fontPath, std::string text, int x, int y, int w, int h, int rr, int rg, int rb, int ra, int cr, int cg, int cb) : Rect(fontPath, text, x, y, w, h, rr, rg, rb, ra, cr, cg, cb)
{
	this->id = id;
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
}

gui::Button::~Button()
{
}

bool gui::Button::isPressed(sf::Vector2i mousePos, sf::Event event) {
	if (mousePos.x > this->x && mousePos.x <= this->w + this->x && mousePos.y > this->y && mousePos.y <= this->h + this->y && event.mouseButton.button == sf::Mouse::Left)
	{
		return true;
	}
	return false;	
}

int gui::Button::getId() {
	return this->id;
}

gui::Map::Map() 
{
	this->map_texture.loadFromFile("Map/map.png");
	this->map_sprite.setTexture(map_texture);
	this->map_sprite.setScale(sf::Vector2f(1.5f, 1.5f));
	this->map_sprite.setPosition(1920 / 2 - 600, 1080 / 2 - 600);
}

gui::Map::~Map()
{
}

void gui::Map::renderMap(sf::RenderWindow& window)
{
	window.draw(this->map_sprite);
}

gui::Tower::Tower(std::string path, int x, int y)
{
	this->tower_texture.loadFromFile(path);
	this->tower_sprite.setTexture(tower_texture);
	this->tower_sprite.setScale(sf::Vector2f(0.5f, 0.5f));
	this->tower_sprite.setPosition(x, y);
	this->x = x;
	this->y = y;

}

gui::Tower::~Tower()
{
}

void gui::Tower::renderTower(sf::RenderWindow& window)
{
	window.draw(this->tower_sprite);
}
