#pragma once
#include "Managers.h"
class Enemy
{
public:
	Enemy();
	~Enemy();
	virtual void Init(int x, int y, Managers* manager) = 0;
	virtual void Update(int width, int height) = 0;
	void Draw(SDL_Renderer* r,int width,int height);
	int GetX()
	{
		return int(m_x);
	}
	int GetY()
	{
		return int(m_y);
	}
protected:
	bool Init(Managers* manager,Texture* image, int x, int y, int contactDamage, int speed, int health);

	Managers* m_managers;
	Texture* m_image;
	float m_accelX, m_accelY,m_x,m_y,m_health;
	int m_contactDamage,m_speed;
	bool m_isDead,m_isCollidable;
};

