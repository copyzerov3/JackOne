#include "Enemy.h"

Enemy::Enemy() :m_isDead(false), m_isCollidable(false)
{
}


Enemy::~Enemy()
{
}

bool Enemy::Init(Managers* manager, Texture* image, int x, int y, int contactDamage, int speed, int health)
{
	m_managers = manager;
	m_image = image;
	m_x = x;
	m_y = y;
	m_contactDamage = contactDamage;
	m_speed = speed;
	m_health = health;
	
	return true;
}
