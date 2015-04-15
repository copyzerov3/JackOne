#pragma once
#include "Bullet.h"
class BusterBullet :
	public Bullet
{
public:
	BusterBullet();
	~BusterBullet();

	bool Init(Managers* managers,int x,int y);
};

