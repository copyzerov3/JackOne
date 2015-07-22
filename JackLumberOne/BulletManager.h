#pragma once

#include "Bullet.h"
#include "UnorderedArray.h"
#include "Player.h"
class Bullet;
class Player;
class BulletManager
{
public:
	BulletManager();
	~BulletManager();

	void Add(Bullet* bullet);
	void Update(Player* player);
	void Draw();
private:
	UnorderedArray<Bullet*> m_bullets;
};
