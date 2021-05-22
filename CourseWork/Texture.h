#pragma once
#include "GameObject.h"

class Texture : private GameObject {
public:
	Texture() {
		isCollided = false;
	}
};