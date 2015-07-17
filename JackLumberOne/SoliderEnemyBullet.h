#pragma once
#include "Bullet.h"
class SoliderEnemyBullet :
	public Bullet
{
public:
	SoliderEnemyBullet();
	~SoliderEnemyBullet();

	bool Init(int x, int y);
	void Update();
};

