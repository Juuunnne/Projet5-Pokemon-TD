#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <math.h>

#include <iostream>

//#include "App.h"

#pragma once

class Gui
{
public:
	//Construtor & Destructor
	Gui();
	~Gui();

private:
	const char* id;
	bool buttonIsHover;

};


//Basically all aggregation class are for generate shape, text, also set color, position etc
namespace gui
{

	class Image
	{
	protected:
		sf::Texture texture;
		bool imageLoaded;

	public:
		//Construtor & Destructor
		Image(std::string imagePath);
		~Image();

		void renderImage(sf::RenderWindow& window);

		sf::Sprite sprite;

	};

	class Font
	{
	protected:
		sf::Font font;
		bool fontLoaded;

	public:
		//Construtor & Destructor
		Font(std::string fontPath);
		~Font();

	};

	class Text
		: public Font
	{
	protected:
		sf::RectangleShape* shape;
		sf::Text text;

	public:
		//Construtor & Destructor
		Text(std::string fontPath, std::string text, int x, int y, int r, int g, int b);
		~Text();

	};

	class Rect
		: public Text
	{
	protected:
		sf::RectangleShape rect;

	public:
		//Construtor & Destructor
		Rect(std::string fontPath, std::string text, int x, int y, int w, int h, int rr, int rg, int rb, int ra, int cr, int cg, int cb);
		~Rect();

		void render(sf::RenderWindow& window);
	};

	class Button
		: public Rect
	{
	protected:
		int id;
		int x;
		int y;
		int w;
		int h;

	public:
		//Construtor & Destructor
		Button(int id, std::string fontPath, std::string text, int x, int y, int w, int h, int rr, int rg, int rb, int ra, int cr, int cg, int cb);
		~Button();

		bool isPressed(sf::Vector2i mousePos, sf::Event event);
		bool buildArea(int id, sf::Vector2i mousePos, sf::Event event);
		int getId();

	};

	class Map
	{
	protected:
		sf::Sprite map_sprite;
		sf::Texture map_texture;

	public:
		//Construtor & Destructor
		Map();
		~Map();
		//Render map
		void renderMap(sf::RenderWindow& window);

	};

	class Tower
	{
	protected:
		sf::Sprite tower_sprite;
		sf::Texture tower_texture;

	public:
		//Construtor & Destructor
		Tower(std::string path, int x, int y);
		~Tower();
		//Render Tower sprite
		void renderTower(sf::RenderWindow& window);

		int x;
		int y;
	};
};