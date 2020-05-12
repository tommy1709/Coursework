#pragma once
#include "Framework/TileMap.h"
#include "Framework/GameObject.h"
#include "Framework/Collision.h"
#include "player.h"
#include "enemy_manager.h"

class tiles
{
    TileMap tileMap;
    GameObject tile;
    Collision collision;
    std::vector<GameObject> game_tiles;
    int num;

public:

    tiles();
    ~tiles();

    void render(sf::RenderWindow* window);
    void collisionCheck(player* player);
};


