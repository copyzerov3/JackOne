#include "BusterWeapon.h"
#include "BusterBullet.h"

BusterWeapon::BusterWeapon(Managers* manager)
{
	switch (manager->GetGlobalsManager()->GetBusterLevel())
	{
	case 1:
		m_fireRate = 1000;
		break;
	case 2:
		m_fireRate = 800;
		break;
	case 3:
		m_fireRate = 650;
		break;
	case 4:
		m_fireRate = 500;
		break;
	}
}


BusterWeapon::~BusterWeapon()
{
}

void BusterWeapon::Fire(Managers* manager,int x, int y)
{
	BusterBullet* bullet = new BusterBullet();
	bullet->Init(manager, x, y);
	manager->GetBulletManager()->Add(bullet);
	m_timer.start();
}
