#pragma once
#include "Texture.h"
#include "Managers.h"

class Managers;
class Bullet
{
public:
	Bullet();
	~Bullet();
	bool Init(Managers* managers,int x, int y);
	void Update(int width, int height);
	void Draw(SDL_Renderer* r,int width, int height);
	bool IsDead(){ return m_isDead; }
	int GetWidth()
	{
		return m_image->GetWidth();
	}
	int GetHeight()
	{
		return m_image->GetHeight();
	}
private:
	Texture* m_image;
	int m_speed,m_damage,m_x,m_y;
	bool m_isDead;
protected:
		void Init(Texture* image, int speed, int damage, int x, int y);

};

