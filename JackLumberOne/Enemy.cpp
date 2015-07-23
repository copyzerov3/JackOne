#include "Enemy.h"

Enemy::Enemy() :m_isDead(false), m_isCollidable(false)
{

}


Enemy::~Enemy()
{
}

void Enemy::Init(Texture* image, int x, int y, int contactDamage, int speed, int health)
{
	m_image = image;
	m_x = x;
	m_y = y;
	m_contactDamage = contactDamage;
	m_speed = speed;
	m_health = health;
	m_hitbox.Init(m_x, m_y, image->GetWidth(), image->GetHeight()); 
	m_healthText = new Texture();
	UpdateHealthText();
}
void Enemy::GetAcceleraton(int newX, int newY)
{
	
	if (std::abs(m_x - newX) > std::abs(m_y - newY))
	{
		m_accelX = m_speed;
		m_accelY = std::abs(m_y - newY) / (std::abs(m_x - newX) / m_accelX);
	}
	else if (std::abs(m_x - newX) < std::abs(m_y - newY))
	{
		m_accelY = m_speed;
		m_accelX = std::abs(m_x - newX) / (std::abs(m_y - newY) / m_accelY);
	}
	else
	{
		m_accelX = m_speed;
		m_accelY = m_speed;
	}
}
void Enemy::UpdateHealthText()
{
	SDL_Color color = { 0, 0, 0, 0 };
	m_healthText->LoadFromRenderedText(std::to_string((int)m_health), color, Managers::GetGraphicsManager()->GetFont());
}
