#pragma once
#include "GameObject.h"

class Brick : private GameObject {
public:
	Brick() {
		isCollided = true;
	}
};