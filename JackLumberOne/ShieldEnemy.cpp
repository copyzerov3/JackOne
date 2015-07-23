#include "ShieldEnemy.h"
#include "ScatterBullet.h"

ShieldEnemy::ShieldEnemy() :m_state(STATE::FINDING), m_offset(0.0), m_targetX(0), m_targetY(0)
{
}


ShieldEnemy::~ShieldEnemy()
{
}

bool ShieldEnemy::Init(int x, int y)
{
	Texture* image;
	if (!Managers::GetResourceManager()->GetTexture("shield", image))
	{
		printf("Could not load the shield enemy image\n");
		return false;
	}
	m_targetX = (rand() % Managers::GetGraphicsManager()->GetScreenWidth() - image->GetWidth()) + image->GetWidth() * 2;
	m_targetY = rand() % (Managers::GetGraphicsManager()->GetScreenHeight() - image->GetHeight());
	Enemy::Init(image, x, y, 30, 2, 6);

	GetAcceleraton(m_targetX,m_targetY);
	return true;
}
void ShieldEnemy::Update(Player* playerRef)
{
	if (m_state== STATE::FINDING)
	{
		if (m_x>m_targetX)
		{
			m_x -= m_accelX;
			if (m_x<m_targetX)
			{
				m_x = m_targetX;
			}
		}
		else
		{
			m_x += m_accelX;
			if (m_x>m_targetX)
			{
				m_x = m_targetX;
			}
		}
		if (m_y>m_targetY)
		{
			m_y -= m_accelY;
			if (m_y<m_targetY)
			{
				m_y = m_targetY;
			}
		}
		else
		{
			m_y += m_accelY;
			if (m_y>m_targetY)
				m_y = m_targetY;
		}
		if ((std::abs(m_x - m_targetX) == 1 || std::abs(m_x - m_targetX) == 0) && (std::abs(m_y - m_targetY) == 1 || std::abs(m_y - m_targetY) == 0))
		{
			/*Vector<Enemy> enemies = directorRef.getEnemies();
			for (int i = 0; i<enemies.size(); i++)
			{
				if (enemies.get(i).isCollidable())
				{
					if (BoundingBox.Collided(enemies.get(i).GetBoundingBox(), this.hitBox))
					{
						boolean found = false;
						Random rand = new Random();
						do
						{
							xPos = rand.nextInt(600) + 150;
							yPos = rand.nextInt(380);

							for (int j = 0; j<enemies.size(); j++)
							{
								if (!BoundingBox.Collided(enemies.get(j).GetBoundingBox(), new BoundingBox(xPos, yPos, image.getWidth(), image.getHeight())))
								{
									found = true;
									super.GetAcceleration(xPos, yPos);
								}
							}
						} while (!found);

						hitBox.setPosition((int)x, (int)y + (int)yOffset);
						return;
					}
				}
			}*/
			m_state = STATE::FOUND;
			m_isCollidable = true;

		}
	}
	else
	{
		//yOffset = Math.sin(time) * 20;
	}
	m_hitbox.SetPosition((int)m_x, (int)m_y + (int)m_offset);
}
void ShieldEnemy::Draw()
{
	m_image->Render(m_x, (m_y + m_offset));
	m_healthText->Render(m_x + m_image->GetWidth() - m_healthText->GetWidth(), m_y + m_image->GetHeight() - m_healthText->GetHeight());	
}
void ShieldEnemy::TakeDamage(float damage, bool fromContact)
{
	m_health -= damage;
	UpdateHealthText();
	if (m_health <= 0)
	{
		m_isDead = true;
		return;
	}
	if (!fromContact)
	{
		ScatterBullet* bullet = new ScatterBullet();
		bullet->Init((int)m_x, (int)m_y + (int)m_offset + m_image->GetHeight() / 2, true);

		Managers::GetBulletManager()->Add(bullet);
		bullet = new ScatterBullet();
		bullet->Init((int)m_x, (int)m_y + (int)m_offset + m_image->GetHeight() / 2, false);
		Managers::GetBulletManager()->Add(bullet);
	}
}
