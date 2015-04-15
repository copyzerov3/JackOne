#include "Weapon.h"


Weapon::Weapon()
{
}


Weapon::~Weapon()
{
}

bool Weapon::CanFire()
{
	if (!m_timer.isStarted())
		return true;
	return (m_timer.getTicks() > m_fireRate);
}
