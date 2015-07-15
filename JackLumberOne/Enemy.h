#pragma once
#include "Texture.h"
class Enemy
{
public:
	Enemy();
	~Enemy();
	/*Classes for the basic functionality of the enemies including Updating,Initialising and drawing*/
	virtual void Init(int x, int y) = 0;
	virtual void Update(int width, int height) = 0;
	virtual void Draw(SDL_Renderer* r,int width,int height)=0;
	/*Getters for the base variables in the class*/
	int GetX(){return int(m_x);}
	int GetY(){return int(m_y);}
	float GetAccelX(){return m_accelX;}
	float GetAccelY(){return m_accelY;}
	float GetHealth(){return m_health;}

	void TakeDamage(float damage, bool fromContact)
	{
		m_health -= damage;
	}
protected:
	//This function is for the classes derived from this one to pass in all the values needed
	bool Init(Texture* image, int x, int y, int contactDamage, int speed, int health);
	Texture* m_image;
	float m_accelX, m_accelY,m_x,m_y,m_health;
	int m_contactDamage,m_speed;
	bool m_isDead,m_isCollidable;
};

