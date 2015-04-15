#include "BulletManager.h"


BulletManager::BulletManager() :m_bullets(200)
{
}


BulletManager::~BulletManager()
{
}

void BulletManager::Draw(SDL_Renderer *r,int width,int height)
{
	for (int i = 0; i < m_bullets.GetSize(); i++)
	{
		m_bullets[i]->Draw(r, width, height);
	}
}

void BulletManager::Update(int width, int height)
{
	Bullet* currentBullet;
	for (int i = m_bullets.GetSize()-1; i !=-1; i--)
	{
		currentBullet = m_bullets[i];
		currentBullet->Update(width, height);
		if (currentBullet->IsDead())
		{
			m_bullets.removePointer(i);
		}	
	}
}
void BulletManager::Add(Bullet* bullet)
{
	m_bullets.push(bullet);
}