#include  "App.h"

App::App()
{
}

App::~App()
{
}

void App::mainLoop(App* app)
{
	_window.create(sf::VideoMode(1920, 1080), "Nomekoup", sf::Style::Fullscreen);
	//_window.setVerticalSyncEnabled(true);
	myWindow.displayMenu();

	Enemy g1(0);
	
	g1.setPosition(360, 745);

	while (_window.isOpen())
	{
		sf::Event event;
		while (_window.pollEvent(event))
		{
			isPressed(event);

			if (this->towerId != 0 && event.mouseButton.button == sf::Mouse::Left && !this->pause)
			{
				if (isSelected && allowBuild)
				{
					switch (towerId)
						case 1:
							tower.newTower(towerNumber, mousePos.x, mousePos.y);
							this->towerId = 0;
							this->isSelected = false;
							this->allowBuild = false;
							towerNumber++;
							break;
				}
			}
			if (this->lastRenderedWindowID != this->renderWindow)
			{
				switch (renderWindow)
				{

				case -1:
					myWindow.closePauseMenu();
					this->pause = false;
					break;

				case 0:
					tower.towerList.clear();
					myWindow.closePauseMenu();
					myWindow.displayMenu();
					this->pause = false;
					this->lastRenderedWindowID = 0;
					g1.reset();
					break;

				case 1:
					tower.towerList.clear();
					myWindow.displayMap();
					myWindow.buildArea();
					this->lastRenderedWindowID = 1;
					break;

				case 2:
					myWindow.displaySettings();
					this->lastRenderedWindowID = 2;
					break;

				case 3:
					_window.close();
					break;

				case 101:
					this->towerId = renderWindow - 100;
					this->isSelected = true;
					renderWindow = 1;
					break;

				case 102:
					this->towerId = renderWindow - 100;
					renderWindow = 1;
					break;

				case 103:
					this->towerId = renderWindow - 100;
					renderWindow = 1;
					break;

				}
			}

			if (lastRenderedWindowID == 1)
			{
				if (this->pause == false) {
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
					{
						myWindow.openPauseMenu();
						this->pause = true;
					}
				}
			}

			this->mousePos = sf::Mouse::getPosition(_window);
			//std::cout << this->mousePos.x << "," <<  this->mousePos.y << std::endl;

			if (event.type == sf::Event::Closed)
				_window.close();
		}

		for (auto i : tower.towerList)
		{
			if (abs(i.second->x - g1.pos_x <= 100 && i.second->y - g1.pos_y <= 100))
			{
				if (!g1.return_is_alive())
				{
					std::cout << "hit";
				}
				//g1.pv(1);
			}
		}

		if (!this->pause)
		{
			g1.setAnimRect();
			g1.deplacement();
		}
		//Collision
		//if (g1.GetHitBox().intersects(tower.GetTowerHitArea()))
		//{
		//	if (gameClock.getElapsedTime().asSeconds() > 0.1f)
		//	{
		//		tower.SetAtkSpritePos(g1.GetPosition());
		//	}
		//	tower.RenderATK(_window);

		//	gameClock.restart();
		//}
	/*	else if (tower.GetTowerHitArea().contains((g1.GetHitBox()))
		{


		}*/
		

		

		//Debug
		if (event.mouseButton.button == sf::Mouse::Right) {
		std::cout << "X : " << mousePos.x << " | Y : " << mousePos.y << std::endl;
			std::cout << g1.showPv() << std::endl;
		//	std::cout << allowBuild << std::endl;
		//	std::cout << isSelected << std::endl;
		}
		//Debug

		//Render
		_window.clear();

		render();

		if (renderWindow == 1 && !this->pause || renderWindow == 666 && !this->pause) {
			this->_window.draw(g1.getSprite());
		}
		_window.display();
	}
}

void App::render()
{
	//Render pictures
	for (auto i : myWindow.imageList)
		i.second->renderImage(this->_window);
	for (auto i : myWindow.mapList)
		i.second->renderMap(this->_window);
	for (auto i : myWindow.buildAreaList)
		i.second->render(this->_window);
	//Render Tower
	for (auto i : tower.towerList)
		i.second->renderTower(this->_window);
	for (auto i : myWindow.rectList)
		i.second->render(this->_window);
	for (auto i : myWindow.buttonList)
		i.second->render(this->_window);
	//Render paused menu
	for (auto i : myWindow.pauseRectList)
		i.second->render(this->_window);
	for (auto i : myWindow.pauseButtonList)
		i.second->render(this->_window);
}


//Check which button was clicked on 
void App::isPressed(sf::Event event)
{
	for (auto i : myWindow.buttonList)
		if (i.second->isPressed(this->mousePos, event)) {
			this->renderWindow = i.second->getId();
			if (i.second->getId() == 666) {
				this->allowBuild = true;
			}
			else {
				this->allowBuild = false;
			}
		}
	for (auto i : myWindow.pauseButtonList)
		if (i.second->isPressed(this->mousePos, event)) {
			this->renderWindow = i.second->getId();
		}

	for (auto i : myWindow.buildAreaList)
		if (i.second->isPressed(this->mousePos, event)) {
			this->renderWindow = i.second->getId();
			if (i.second->getId() == 666) {
				this->allowBuild = true;
			}
			else {
				this->allowBuild = false;
			}
		}
}

