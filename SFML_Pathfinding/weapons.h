#pragma once

#include "util.h"

class Weapon
{
private:

public:
	
	uint16_t ammunition[2]; //0 represents clip, 1 represents total ammo count
	uint16_t spreadRange[2]; //0 is min, 1 is max
	uint16_t damageRange[2];

	float fireRate = 1.0f;

	Weapon();
};

class WeaponsManager //static class
{
	
};