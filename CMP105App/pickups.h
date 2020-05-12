#pragma once
#include "Framework/GameObject.h"
#include"Framework/Vector.h"
#include "math.h"

class pickups: public GameObject
{

public:

	pickups();
	~pickups();
	void update(float dt) override;
};

