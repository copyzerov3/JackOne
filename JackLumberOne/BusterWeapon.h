#pragma once
#include "Weapon.h"
class BusterWeapon :
	public Weapon
{
public:
	BusterWeapon();
	~BusterWeapon();
	void Fire(int x, int y);
};

