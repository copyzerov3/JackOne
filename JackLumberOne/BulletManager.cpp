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

void BulletManager::Update(Player* player)
{
	Bullet* currentBullet;
	for (int i = m_bullets.GetSize()-1; i !=-1; i--)
	{
		currentBullet = m_bullets[i];
		currentBullet->Update();
		if (currentBullet->IsEnemy())
		{
			if (BoundingBox::Collided(player->GetBoundingBox(), currentBullet->GetBoundingBox()))
			{
				printf("Enemy Bullet hit player\n");
				currentBullet->HitSomething();
				player->TakeDamage(currentBullet->GetDamage());
			}
		}
		else
		{
			for (int i = 0; i < Managers::GetAIDirector()->m_enemies.GetSize(); i++)
			{
				if (BoundingBox::Collided(currentBullet->GetBoundingBox(), Managers::GetAIDirector()->m_enemies[i]->GetBoundingBox()))
				{
					printf("player bullet hit enemy\n");
					currentBullet->HitSomething();
					Managers::GetAIDirector()->m_enemies[i]->TakeDamage(currentBullet->GetDamage(), false);
				}
			}
		}
		if (currentBullet->IsDead())
		{
			printf("Removed Bullet\n");
			m_bullets.removePointer(i);
		}	
	}
}
void BulletManager::Add(Bullet* bullet)
{
	m_bullets.push(bullet);
}