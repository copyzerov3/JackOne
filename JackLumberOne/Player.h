#pragma once
#include "Texture.h"
#include "Weapon.h"
#include "BoundingBox.h"
class Weapon;
class Player
{
public:
	Player();
	~Player();
	bool Init();
	void Draw();
	void Update();
	int GetX()
	{
		return m_x;
	}
	int GetY()
	{
		return m_y;
	}
	int GetWidth()
	{
		return m_player->GetWidth();
	}
	int GetHeight()
	{
		return m_player->GetHeight();
	}
	BoundingBox GetBoundingBox()
	{
		return m_hitbox;
	}
	void TakeDamage(float damage);
	bool CanBeHit(){ return m_hitTimer.getTicks() > m_hitTime; }
private:
	Texture *m_player,*m_healthLabel;
	BoundingBox m_hitbox;
	Timer m_hitTimer;
	Weapon *m_weapon;
	int m_x, m_y,m_hitTime;
	float m_health,m_maxHealth;
	const int m_speed = 5;
	
	void UpdateHealthText();
	
	
};

