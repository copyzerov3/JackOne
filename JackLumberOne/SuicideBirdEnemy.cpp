#include "SuicideBirdEnemy.h"


SuicideBirdEnemy::SuicideBirdEnemy()
{
	m_state = STATE::TARGETING;
}


SuicideBirdEnemy::~SuicideBirdEnemy()
{
}

bool SuicideBirdEnemy::Init(int x, int y)
{
	Texture* image;
	if (!Managers::GetResourceManager()->GetTexture("bird", image))
	{
		printf("Could not load the image for the suicide birds XD\n");
		return false;
	}

	Enemy::Init(image, x, y, 10, 2, 1);
	return true;
}
void SuicideBirdEnemy::Draw()
{
	m_image->Render(m_x, (m_y + m_offset));
}
void SuicideBirdEnemy::Update(Player* playerRef)
{
	if (m_state == STATE::TARGETING)
	{
		//yOffset = Math.sin(time) * 15;

		m_x -= m_speed;

		if (m_y> playerRef->GetY() + playerRef->GetHeight() / 2)
		{
			m_y -= m_speed;
			if (m_y< playerRef->GetY() + playerRef->GetHeight() / 2)
			{
				m_y = playerRef->GetY() + playerRef->GetHeight() / 2;
			}
		}
		else if (m_y< playerRef->GetY() + playerRef->GetHeight() / 2)
		{
			m_y += m_speed;
			if (m_y> playerRef->GetY() + playerRef->GetHeight() / 2)
			{
				m_y = playerRef->GetY() + playerRef->GetHeight() / 2;
			}
		}

		if (m_x <= 500)
		{
			m_state = STATE::ATTACKING;
		}
	}
	else
	{
		m_x -= 10;
	}

	//hitBox.setPosition((int)x, (int)y + (int)yOffset);

	if (m_x + m_image->GetWidth() <= 0)
	{
		m_isDead = true;
	}
}