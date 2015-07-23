#pragma once
#include "Player.h"
#include "Managers.h"
#include"BoundingBox.h"
class Enemy
{
public:
	Enemy();
	~Enemy();
	/*Classes for the basic functionality of the enemies including Updating,Initialising and drawing*/
	virtual bool Init(int x, int y) = 0;
	virtual void Update(Player* playerRef) = 0;
	virtual void Draw()=0;
	virtual void TakeDamage(float damage, bool fromContact) = 0;
	/*Getters for the base variables in the class*/
	int GetX(){return int(m_x);}
	int GetY(){return int(m_y);}
	float GetAccelX(){return m_accelX;}
	float GetAccelY(){return m_accelY;}
	float GetHealth(){return m_health;}
	bool IsCollidable(){ return m_isCollidable; }
	bool IsDead(){ return m_isDead; }
	int GetContactDamage(){ return m_contactDamage; }
	BoundingBox GetBoundingBox()
	{
		return m_hitbox;
	}
	

protected:
	//This function is for the classes derived from this one to pass in all the values needed
	void Init(Texture* image, int x, int y, int contactDamage, int speed, int health);
	void SetPosition(int x, int y)
	{
		m_x = (float)x;
		m_y = (float)y;
	}
	void GetAcceleraton(int newX, int newY);
	void UpdateHealthText();


	Texture* m_image, *m_healthText;
	float m_accelX, m_accelY,m_x,m_y,m_health;
	int m_contactDamage,m_speed;
	bool m_isDead,m_isCollidable;
	BoundingBox m_hitbox;
};

