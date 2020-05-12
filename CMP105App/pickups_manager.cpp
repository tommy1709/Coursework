#include "pickups_manager.h"

pickups_manager::pickups_manager()
{
    texture_1.loadFromFile("gfx/double_kill.png");
    texture_2.loadFromFile("gfx/less_10.png");
    texture_3.loadFromFile("gfx/plus_life.png");

    for (int i = 0; i < 15; i++)
    {
        pkups.push_back(pickups());
        pkups[i].setAlive(false);
        pkups[i].setSize(sf::Vector2f(32, 32));
    }
}

pickups_manager::~pickups_manager()
{

}

void pickups_manager::update(float dt)
{
    for (int i = 0; i < pkups.size(); i++)
    {
        if (pkups[i].isAlive())
        {
            pkups[i].update(dt);
        }
    }
    
}

void pickups_manager::spawn(int num, float x, float y)
{
   
    for (int i = 0; i < pkups.size(); i++)
    {
        if (!pkups[i].isAlive())
        {
            pkups[i].setAlive(true);
            pkups[i].setPosition(x, y);

            if (num == 1)
            {
                pkups[i].setTexture(&texture_1);
                val = 1;
            }
            else if (num == 2)
            {
                pkups[i].setTexture(&texture_2);
                val = 2;
            }
            else if (num == 3)
            {
                pkups[i].setTexture(&texture_3);
                val = 3;
            }

            return;
        }


    }
}

void pickups_manager::collisionCheck(GameObject* player, disp_text* text)
{
    for (int i = 0; i < pkups.size(); i++)
    {
        if (pkups[i].isAlive())
        {
            if (Collision::checkBoundingBox(player, &pkups[i]))
            {
                pkups[i].setAlive(false);
                text->setter(true, val, true); text->restart_clock();
               // if (val == 1) { kills->set_check(true); }

            }
        }
    }
}

void pickups_manager::render(sf::RenderWindow* window)
{
    for (int i = 0; i < pkups.size(); i++)
    {
        if (pkups[i].isAlive())
        {
            window->draw(pkups[i]);
        }
    }
}