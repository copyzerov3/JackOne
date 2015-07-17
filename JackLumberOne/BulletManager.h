#pragma once

#include "Bullet.h"
#include "UnorderedArray.h"
class Bullet;
class BulletManager
{
public:
	BulletManager();
	~BulletManager();

	void Add(Bullet* bullet);
	void Update();
	void Draw();
private:
	UnorderedArray<Bullet*> m_bullets;
};
