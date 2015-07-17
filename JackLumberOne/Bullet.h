#pragma once
#include "Managers.h"
class Bullet
{
public:
	Bullet();
	~Bullet();
	bool Init(int x, int y);
	virtual void Update() = 0;
	void Draw();
	bool IsDead(){ return m_isDead; }
	int GetWidth()
	{
		return m_image->GetWidth();
	}
	int GetHeight()
	{
		return m_image->GetHeight();
	}
protected:
	Texture* m_image;
	int m_speed,m_damage,m_x,m_y;
	bool m_isDead,m_isEnemy;
	void Init(Texture* image, int speed, int damage, int x, int y,bool isEnemy = false);

};

