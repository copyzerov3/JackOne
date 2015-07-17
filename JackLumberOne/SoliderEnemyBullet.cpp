#include "SoliderEnemyBullet.h"


SoliderEnemyBullet::SoliderEnemyBullet()
{
}


SoliderEnemyBullet::~SoliderEnemyBullet()
{
}

bool SoliderEnemyBullet::Init(int x, int y)
{
	Texture* image;
	if (!Managers::GetResourceManager()->GetTexture("BusterBulletOne", image))
	{
		printf("Could not get BusterBulletOne for solider enemy bullet");
		return false;
	}

	Bullet::Init(image, 5, 10, x - image->GetWidth(), y, true); 
	return true;
}

void SoliderEnemyBullet::Update()
{
	m_x -= m_speed;
	if (m_x + m_image->GetWidth() <= 0)
		m_isDead = true;
}
