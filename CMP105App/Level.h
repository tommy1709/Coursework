#pragma once

#include <SFML/Graphics.hpp>
#include "Framework/Input.h"
#include "Framework/AudioManager.h"
#include "Framework/GameState.h"
#include <string>
#include <iostream>
#include "tiles.h"
#include "player.h"
#include "Framework/TileMap.h"
#include "background.h"
#include "enemy_manager.h"
#include <Windows.h>
#include "dispTime.h"
#include "disp_text.h"
#include "kill_count.h"
#include"pickups_manager.h"
#include "menu.h"
#include "instruct.h"
#include "pause.h"
#include "score.h"


class Level{
public:
	Level(sf::RenderWindow* hwnd, Input* in);
	~Level();

	void handleInput(float dt);
	void update(float dt);
	void render();

private:
	// Default functions for rendering to the screen.
	void beginDraw();
	void endDraw();

	// Default variables for level class.
	int num = 0;
	bool pause_check = false;
	
	sf::RenderWindow* window;
	Input* input;
	GameState* gameState;
	AudioManager* audio;
	player player;
	tiles tiles;
	TileMap tileMap;
	background background;
	sf::View view;
	enemy_manager enemies;
	dispTime time;
	disp_text text;
	kill_count kills;
	pickups_manager pickups;
	menu menu; 
	score score;
	instruct instruct;
	pause pause;
	




};