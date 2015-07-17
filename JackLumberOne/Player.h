#pragma once
#include "Texture.h"
#include "Timer.h"
#include "Weapon.h"
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
private:
	Texture *m_player;
	int m_x, m_y;
	Timer m_timer;
	const int m_speed = 5;
	Weapon* m_weapon;
};

