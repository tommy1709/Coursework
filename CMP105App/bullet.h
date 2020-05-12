#pragma once
#include "Framework/GameObject.h"
#include "player.h"

class bullet : public GameObject
{


public:

	bullet();
	~bullet();
	void update(float dt);
};

