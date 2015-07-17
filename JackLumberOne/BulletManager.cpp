#include "BulletManager.h"


BulletManager::BulletManager() :m_bullets(200)
{
}


BulletManager::~BulletManager()
{
}

void BulletManager::Draw()
{
	for (int i = 0; i < m_bullets.GetSize(); i++)
	{
		m_bullets[i]->Draw();
	}
}

void BulletManager::Update()
{
	Bullet* currentBullet;
	for (int i = m_bullets.GetSize()-1; i !=-1; i--)
	{
		currentBullet = m_bullets[i];
		currentBullet->Update();
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