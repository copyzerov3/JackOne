#include "ScatterBullet.h"


ScatterBullet::ScatterBullet() :m_up(false)
{
}


ScatterBullet::~ScatterBullet()
{
}

bool ScatterBullet::Init(int x, int y, bool up)
{
	Texture* image;
	if (!Managers::GetResourceManager()->GetTexture("scatterBullet", image))
	{
		printf("Could not load the image for the scatter bullet\n");
		return false;
	}
	m_up = up;
	Bullet::Init(image, 3, 5, x- image->GetWidth(), y, true);
	return true;
}
void ScatterBullet::Update()
{
	m_x -= m_speed;

	if (m_up)
	{
		m_y -= m_speed;
	}
	else
	{
		m_y += m_speed;
		if (m_y + m_image->GetHeight() >= Managers::GetGraphicsManager()->GetScreenHeight())
		{
			m_up = true;
		}
	}

	if (m_x + m_image->GetWidth() <= 0)
	{
		
		m_isDead = true;
		return;
	}
	//hitBox.setPosition(x, y);
}
