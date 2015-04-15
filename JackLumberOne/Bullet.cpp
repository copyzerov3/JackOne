#include "Bullet.h"


Bullet::Bullet() :m_isDead(false)
{
}


Bullet::~Bullet()
{
}
void Bullet::Init(Texture* image, int speed, int damage, int x, int y)
{
	m_image = image;
	m_speed = speed;
	m_damage = damage;
	m_x = x;
	m_y = y;
	m_isDead = false;
}
void Bullet::Update(int WIDTH, int HEIGHT)
{
	m_x += m_speed;
	if (m_x >= WIDTH)
		m_isDead = true;
}
void Bullet::Draw(SDL_Renderer *r,int width, int height)
{
	m_image->Render(r, m_x, m_y);
}