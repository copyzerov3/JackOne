#pragma once
#include "Bullet.h"
class BusterBullet :
	public Bullet
{
public:
	BusterBullet();
	~BusterBullet();

	bool Init(int x,int y);
};

