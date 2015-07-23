#include "SuicideBirdEnemy.h"


SuicideBirdEnemy::SuicideBirdEnemy() :m_state(STATE::TARGETING), m_offset(0)
{
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
	m_healthText->Render(m_x + m_image->GetWidth() - m_healthText->GetWidth(), m_y + m_image->GetHeight() - m_healthText->GetHeight());
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

	m_hitbox.SetPosition((int)m_x, (int)m_y + (int)m_offset);

	if (m_x + m_image->GetWidth() <= 0)
	{
		m_isDead = true;
	}
}
void SuicideBirdEnemy::TakeDamage(float damage, bool fromContact)
{
	m_health -= damage;
	UpdateHealthText();
	if (m_health <= 0)
	{
		m_isDead = true;
	}
}