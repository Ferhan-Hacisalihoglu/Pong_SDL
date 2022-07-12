#pragma once
#include "GameObject.h"

class Ball:public GameObject
{
public:
	void Move(double deltaTime);
};
