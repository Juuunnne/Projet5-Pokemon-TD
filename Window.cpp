#include"Window.h"

Window::Window()
{
}

Window::~Window()
{
}

void Window::displayMenu()
{
	this->imageList.clear();
	this->buttonList.clear();
	this->rectList.clear();
	this->mapList.clear();
	this->buildAreaList.clear();
	this->imageList["BG"] = new gui::Image("./Backgroud/TDBG.png");
	this->buttonList["START"] = new gui::Button(1, "./Font/pokemon.ttf", "START", 255, 250, 300, 75, 0, 0, 0, 0, 255, 255, 255);
	this->buttonList["SETTINGS"] = new gui::Button(2, "./Font/pokemon.ttf", "SETTINGS", 255, 300, 300, 75, 0, 0, 0, 0, 255, 255, 255);
	this->buttonList["EXIT"] = new gui::Button(3, "./Font/pokemon.ttf", "EXIT", 255, 350, 300, 75, 0, 0, 0, 0, 255, 255, 255);
}

void Window::displaySettings()
{
	this->imageList.clear();
	this->buttonList.clear();
	this->rectList.clear();
	this->mapList.clear();
	this->imageList["BG"] = new gui::Image("./Backgroud/Pikadrunk.png");
	this->buttonList["BACK"] = new gui::Button(0, "./Font/pokemon.ttf", "BACK", 20, 1000, 300, 75, 0, 0, 0, 0, 255, 255, 255);
}

void Window::displayMap()
{
	this->mapList.clear();
	this->imageList.clear();
	this->buttonList.clear();
	this->rectList.clear();
	this->mapList.clear();
	this->mapList["Map"] = new gui::Map();

	this->buttonList["Pikachu"] = new gui::Button(101, "./Font/pokemon.ttf", "Pikachu", 20, 100, 300, 75, 150, 150, 150, 100, 255, 255, 255);
	this->buttonList["Charmander"] = new gui::Button(102, "./Font/pokemon.ttf", "Charmander", 20, 200, 300, 75, 150, 150, 150, 100, 255, 255, 255);
	this->buttonList["Noctowl"] = new gui::Button(103, "./Font/pokemon.ttf", "Noctowl", 20, 300, 300, 75, 150, 150, 150, 100, 255, 255, 255);
}

void Window::openPauseMenu()
{
	this->pauseRectList["BG"] = new gui::Rect("./Font/pokemon.ttf", "", 0, 0, 1920, 1080, 0, 0, 0, 220, 0, 0, 0);
	this->pauseButtonList["BACK"] = new gui::Button(0, "./Font/pokemon.ttf", "BACK TO MENU", 20, 1000, 300, 75, 0, 0, 0, 0, 255, 255, 255);
	this->pauseButtonList["RESUME"] = new gui::Button(-1, "./Font/pokemon.ttf", "RESUME", 20, 80, 300, 75, 0, 0, 0, 0, 255, 255, 255);
}

void Window::closePauseMenu()
{
	this->pauseRectList.clear();
	this->pauseButtonList.clear();
}

void Window::test(int id, int x, int y) {
	this->towerList[std::to_string(id)] = new gui::Rect("", "", x-10, y-10, 20, 20, 255, 255, 255, 255, 255, 255, 255);
}

void Window::buildArea() {
	this->buildAreaList["BA1"] = new gui::Button(666, "./Font/pokemon.ttf", "", 1003, 302, 180, 290, 0, 0, 255, 100, 255, 255, 255);
	this->buildAreaList["BA2"] = new gui::Button(666, "./Font/pokemon.ttf", "", 754, 309, 180, 290, 0, 0, 255, 100, 255, 255, 255);
	this->buildAreaList["BA3"] = new gui::Button(666, "./Font/pokemon.ttf", "", 702, 186, 538, 60, 0, 0, 255, 100, 255, 255, 255);
	this->buildAreaList["BA4"] = new gui::Button(666, "./Font/pokemon.ttf", "", 821, 785, 110, 110, 0, 0, 255, 100, 255, 255, 255);
	this->buildAreaList["BA5"] = new gui::Button(666, "./Font/pokemon.ttf", "", 987, 790, 142, 110, 0, 0, 255, 100, 255, 255, 255);
	this->buildAreaList["BA6"] = new gui::Button(666, "./Font/pokemon.ttf", "", 566, 830, 175, 70, 0, 0, 255, 100, 255, 255, 255);
	this->buildAreaList["BA7"] = new gui::Button(666, "./Font/pokemon.ttf", "", 1205, 830, 135, 70, 0, 0, 255, 100, 255, 255, 255);
}