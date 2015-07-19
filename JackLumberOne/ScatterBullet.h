#pragma once
#include "Bullet.h"
class ScatterBullet :
	public Bullet
{
public:
	ScatterBullet();
	~ScatterBullet();

	bool Init(int x, int y,bool up);
	void Update();
private:
	bool m_up;
};

