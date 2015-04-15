#pragma once
#include "Weapon.h"
class BusterWeapon :
	public Weapon
{
public:
	BusterWeapon(Managers* manager);
	~BusterWeapon();
	void Fire(Managers* manager,int x, int y);
};

