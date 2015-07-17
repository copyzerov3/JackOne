#include "Bullet.h"


Bullet::Bullet() :m_isDead(false)
{
}


Bullet::~Bullet()
{
}
void Bullet::Init(Texture* image, int speed, int damage, int x, int y, bool isEnemy)
{
	m_image = image;
	m_speed = speed;
	m_damage = damage;
	m_x = x;
	m_y = y;
	m_isDead = false;
	m_isEnemy = isEnemy;
}
void Bullet::Draw()
{
	m_image->Render( m_x, m_y);
}