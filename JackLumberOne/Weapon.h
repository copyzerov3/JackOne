#pragma once
#include "Timer.h"
#include "Bullet.h"
class Weapon
{
public:
	Weapon();
	~Weapon();
	bool CanFire();
	virtual void Fire(Managers* managers,int x, int y) = 0;
protected:
	Timer m_timer;
	unsigned int m_fireRate;//In milliseconds
};

