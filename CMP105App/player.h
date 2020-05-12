#pragma once
#include "Framework/GameObject.h"
#include "Framework/Animation.h"


class player: public GameObject
{
	sf::Texture texture;

	Animation run;
	Animation slide;
	Animation idle;
	Animation* currentAnimation;

	bool check = false;
	bool second_check = false;
	float speed;
	float scale;
	sf::Vector2f gravity;
	sf::Vector2f stepVelocity;
	sf::Vector2f zero = sf::Vector2f(0, 0);

public:

	player();
	~player();

	void update(float dt) override;
	void handleInput(float dt) override;
	void life();
	void collision_resp_tile(GameObject* collider);
	void collision_resp_pickup(GameObject* collider);
	void collision_resp_enemy(GameObject* collider);
};



