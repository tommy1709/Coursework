#include "enemy.h"

enemy::enemy()
{
	//texture.loadFromFile("gfx/rainbow_enemy.png");
	//setSize(sf::Vector2f(80, 135));
	//setPosition(1000, 300);
	setTexture(&texture);
	setCollisionBox(40, 0, 2, 135);

	idle.addFrame(sf::IntRect(16, 0, 16, 27));
	idle.setFrameSpeed(1.f / 10.f);

	run.addFrame(sf::IntRect(0, 0, 16, 27));
	run.addFrame(sf::IntRect(16, 0, 16, 27));
	run.addFrame(sf::IntRect(32, 0, 16, 27));
	run.addFrame(sf::IntRect(48, 0, 16, 27));
	run.setFrameSpeed(1.f/ 0.3f);

	currentAnimation = &idle;

	speed = 5.f;
	scale = 200.f;
	gravity = sf::Vector2f(0, 9.8f) * scale;
}

enemy::~enemy()
{

}

void enemy::update(float dt, int num, int target_x, int start_x)
{
	
	    if (num == 1)
		{
			currentAnimation = &idle;
		}
		else if (num == 2)
		{
			currentAnimation = &run;
			run.animate(dt);
			target = sf::Vector2f(target_x, getPosition().y);
			start_point = sf::Vector2f(start_x, getPosition().y);

			if (getPosition() != target && check == false)
			{
				direction = target - getPosition();
				direction = Vector::normalise(direction);
				velocity = direction * speed;
				setPosition(getPosition() + (velocity * dt));

				if (Vector::magnitude(target - getPosition()) < 10.f)
				{
					setPosition(target);
					check = true;
					run.setFlipped(true);
				}
			}
			else
			{
				direction = start_point - getPosition();
				direction = Vector::normalise(direction);
				velocity = direction * speed;
				setPosition(getPosition() + (velocity * dt));

				if (Vector::magnitude(start_point - getPosition()) < 10.f)
				{
					setPosition(start_point);
					check = false;
					run.setFlipped(false);

					if (run.getPlaying() == false)
					{
						complete = true;
					}
				}
			}


		}
		
		setTextureRect(currentAnimation->getCurrentFrame());
	
}

