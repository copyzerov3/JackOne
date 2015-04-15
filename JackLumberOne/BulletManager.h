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
	void Update(int width,int height);
	void Draw(SDL_Renderer *r,int width,int height);
private:
	UnorderedArray<Bullet*> m_bullets;
};
