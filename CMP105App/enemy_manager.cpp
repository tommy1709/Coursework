#include "enemy_manager.h"

enemy_manager::enemy_manager()
{
	//spawnpoint = sf::Vector2f(1100, 10);
	texture.loadFromFile("gfx/rainbow_enemy.png");

	for (int i = 0; i < 36; i++)
	{
		enemys.push_back(enemy());
		enemys[i].setSize(sf::Vector2f(80, 135));
		enemys[i].setTexture(&texture);
		enemys[i].setAlive(false);
	}
}

enemy_manager::~enemy_manager()
{

}

void enemy_manager::update(float dt)
{
	for (int i = 0; i < enemys.size(); i++)
	{
		if (enemys[i].isAlive())
		{
			enemys[0].update(dt, 2, 1000, 1500);
			enemys[1].update(dt, 1, 0, 0);
			enemys[2].update(dt, 1, 0, 0);
			enemys[3].update(dt, 2, 2400, 2490);
			enemys[4].update(dt, 2, 2650, 2770);
			enemys[5].update(dt, 2, 2930, 3080);
			enemys[6].update(dt, 2, 3300, 3600);
			enemys[7].update(dt, 1, 0, 0);
			enemys[8].update(dt, 1, 0, 0);
			enemys[9].update(dt, 1, 0, 0);
			enemys[10].update(dt, 2, 4700, 4900);
			enemys[11].update(dt, 2, 5400, 5500);
			enemys[12].update(dt, 2, 5650, 6850);
			enemys[13].update(dt, 2, 5650, 6850);
			enemys[14].update(dt, 2, 5650, 6850);
			enemys[15].update(dt, 2, 5650, 6850);
			enemys[16].update(dt, 2, 5650, 6850);
			enemys[17].update(dt, 2, 5650, 6850);
			enemys[18].update(dt, 2, 5650, 6850);
			enemys[19].update(dt, 2, 5650, 6850);
			enemys[20].update(dt, 2, 5650, 6850);
			enemys[21].update(dt, 2, 5650, 6850);
			enemys[22].update(dt, 2, 5650, 6850);
			enemys[23].update(dt, 2, 5650, 6850);
			enemys[24].update(dt, 1, 0, 0);
			enemys[25].update(dt, 2, 7030, 7380);
			enemys[26].update(dt, 2, 7550, 7730);
			enemys[27].update(dt, 2, 7900, 8080);
			enemys[28].update(dt, 2, 8250, 8430);
			enemys[29].update(dt, 2, 8790, 8970);
			enemys[30].update(dt, 2, 8990, 9170);
			enemys[31].update(dt, 2, 9190, 9370);
			enemys[32].update(dt, 2, 9400, 9900);
			enemys[33].update(dt, 2, 9400, 9900);
			enemys[34].update(dt, 2, 9400, 9900);
			enemys[35].update(dt, 2, 9400, 9900);
			
		}
	}

}

void enemy_manager::spawn()
{
	for (int i = 0; i < enemys.size(); i++)
	{
		if (!enemys[i].isAlive())
		{
			enemys[i].setAlive(true);
			enemys[0].setPosition(1500, 677);
			enemys[1].setPosition(50, 477);
			enemys[2].setPosition(2050, 477);
			enemys[3].setPosition(2400, 677);
			enemys[4].setPosition(2650, 677);
			enemys[5].setPosition(2930, 677);
			enemys[6].setPosition(3300, 677);
			enemys[7].setPosition(4240, 127);
			enemys[8].setPosition(4500, 477);
			enemys[9].setPosition(4580, 127);
			enemys[10].setPosition(4700, 527);
			enemys[11].setPosition(5450, 127);
			enemys[12].setPosition(5650, 677);
			enemys[13].setPosition(5750, 677);
			enemys[14].setPosition(5850, 677);
			enemys[15].setPosition(5950, 677);
			enemys[16].setPosition(6050, 677);
			enemys[17].setPosition(6150, 677);
			enemys[18].setPosition(6250, 677);
			enemys[19].setPosition(6350, 677);
			enemys[20].setPosition(6450, 677);
			enemys[21].setPosition(6550, 677);
			enemys[22].setPosition(6650, 677);
			enemys[23].setPosition(6750, 677);
			enemys[24].setPosition(6950, 127);
			enemys[25].setPosition(7100, 677);
			enemys[26].setPosition(7600, 677);
			enemys[27].setPosition(7900, 677);
			enemys[28].setPosition(8250, 677);
			enemys[29].setPosition(8800, 577);
			enemys[30].setPosition(9000, 477);
			enemys[31].setPosition(9190, 377);
			enemys[32].setPosition(9400, 677);
			enemys[33].setPosition(9500, 677);
			enemys[34].setPosition(9600, 677);
			enemys[35].setPosition(9700, 677);

			
			return;
		}
	}
}

void enemy_manager::collisionCheck(player* player)
{
	for (int i = 0; i < enemys.size(); i++)
	{
		if (enemys[i].isAlive())
		{
			if (Collision::checkBoundingBox(player, &enemys[i]))
			{
				player->collision_resp_enemy(&enemys[i]);
				collision_resp_player(player, i);
			}
		}
	}
}

void enemy_manager::collision_resp_player(GameObject* collider, int num)
{

	if (abs(enemys[num].getPosition().x - collider->getPosition().x) < abs(enemys[num].getPosition().y - collider->getPosition().y))
	{
		if (enemys[num].getPosition().y > collider->getPosition().y)
		{
			 enemys[num].setAlive(false);
			 check = true;
			 death_xpos = enemys[num].getPosition().x;
			 death_ypos = enemys[num].getPosition().y;
			 rand_num = rand() % 15 + 1;

			 if (collider->getPosition().y == 0) 
			 {
					 enemys[num].setAlive(true);
					 check = false;
					 rand_num = 4;
			 }
		}
		else 
		{}
	}
	else {}
}

float enemy_manager::get_xpos()
{
	return death_xpos;
}

float enemy_manager::get_ypos()
{
	return death_ypos;
}

int enemy_manager::get_rand()
{
	return rand_num;
}

bool enemy_manager::get_check()
{
	return check;
}

void enemy_manager::set_rand(int rand)
{
	rand_num = rand;
}

void enemy_manager::set_check(bool set)
{
	check = set;
}

void enemy_manager::render(sf::RenderWindow* window)
{
	for (int i = 0; i < enemys.size(); i++)
	{
		if (enemys[i].isAlive())
		{
			window->draw(enemys[i]);
		}
	}
}