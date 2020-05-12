#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;
	num = 1;
	// initialise game objects
	
	
	player.setInput(input);
	view.setSize(1200, 900);
	view.setCenter(sf::Vector2f(600, 450));
	for (int i = 0; i < 36; i++) { enemies.spawn(); }
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	if (num == 1)
	{
		if (input->isKeyDown(sf::Keyboard::Enter))
		{
			input->setKeyUp(sf::Keyboard::Enter);
			num++;
		}

		if (input->isKeyDown(sf::Keyboard::Q))
		{
			window->close();
			input->setKeyUp(sf::Keyboard::Q);
		}
		
		
	}
	if (num == 2)
	{

		if (input->isKeyDown(sf::Keyboard::Enter))
		{
			input->setKeyUp(sf::Keyboard::Enter);
			num++;
			time.start_clock();
		}
		
		if (input->isKeyDown(sf::Keyboard::Escape))
		{
			input->setKeyUp(sf::Keyboard::Escape);
			num--;
		}
	}
	if (num == 3)
	{
		if (input->isKeyDown(sf::Keyboard::Escape))
		{
			input->setKeyUp(sf::Keyboard::Escape);
			pause_check = true;
		}

		if (pause_check == true)
		{
			if (input->isKeyDown(sf::Keyboard::Enter))
			{
				input->setKeyUp(sf::Keyboard::Enter);
				pause_check = false;
			}

			if (input->isKeyDown(sf::Keyboard::Q))
			{
				input->setKeyUp(sf::Keyboard::Q);
				num -= 2;
				pause_check = false;
			}

		}
	}
	else if (num == 4)
	{
		if (input->isKeyDown(sf::Keyboard::Enter))
		{
			input->setKeyUp(sf::Keyboard::Enter);
			num = 1;
		}
	}
}

// Update game objects
void Level::update(float dt)
{

	if (num == 1) 
	{ 
		view.setCenter(sf::Vector2f(600, 450)); 
		enemies.spawn();
		player.setPosition(100, 100);
		kills.reset_kills();
		score.reset_score();

	}
	else if (num ==2 ) 
	{ 
		view.setCenter(sf::Vector2f(600, 450)); 
		
	}

	else if (num == 3 && pause_check == false)
	{
		tiles.collisionCheck(&player);
		player.handleInput(dt);
		player.update(dt);

		if (player.getPosition().x < 100)
		{
			view.setCenter(sf::Vector2f(600, 450));
		}
		else if (player.getPosition().x > 8900)
		{
			view.setCenter(sf::Vector2f(9400, 450));
		}
		else
		{
			view.setCenter(sf::Vector2f(player.getPosition().x + 500, 450));
		}

		enemies.collisionCheck(&player);
		enemies.update(dt);
		text.update(&player, &kills, &time);
		time.update(&player);
		kills.update(&player, &enemies);
		pickups.update(dt);
		pickups.collisionCheck(&player, &text);

		if (enemies.get_rand() < 4)
		{
			if (enemies.get_rand() == 1) { pickups.spawn(1, enemies.get_xpos(), enemies.get_ypos() + 103); enemies.set_rand(5); }
			if (enemies.get_rand() == 2) { pickups.spawn(2, enemies.get_xpos(), enemies.get_ypos() + 103); enemies.set_rand(5); }
			if (enemies.get_rand() == 3) { pickups.spawn(3, enemies.get_xpos(), enemies.get_ypos() + 103); enemies.set_rand(5); }
		}

		pause.setPosition(view.getCenter().x -250, view.getCenter().y - 300);

		if (player.getPosition().x > 10000) { num = 4; }
	}
	else if (num == 4)
	{
		
		view.setCenter(sf::Vector2f(600, 450));
		score.update(&time, &kills);
	}
}

// Render level
void Level::render()
{
	beginDraw();
	if (num == 1)
	{
		window->draw(menu);
	}
	else if (num == 2) 
	{ 
		window->draw(instruct);
	}
	else if (num == 3)
	{
		window->draw(background);
		tiles.render(window);
		window->draw(player);
		enemies.render(window);
		time.Render(window);
		kills.Render(window);
		pickups.render(window);
		text.Render(window);

		if (pause_check == true) { window->draw(pause); }
	}
	else if (num == 4)
	{
		window->draw(score);
		score.render(window);
	}

	window->setView(view);

	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color::Black);
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}