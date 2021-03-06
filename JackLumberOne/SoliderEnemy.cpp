#include "SoliderEnemy.h"
#include "SoliderEnemyBullet.h"
#include <time.h>
SoliderEnemy::SoliderEnemy() :m_state(STATE::FINDING), m_offset(0.0f), m_shootRate(0.0f), m_targetX(0), m_targetY(0)
{
}


SoliderEnemy::~SoliderEnemy()
{
}

bool SoliderEnemy::Init(int x, int y)
{
	Texture *image;
	if (!Managers::GetResourceManager()->GetTexture("hover", image))
	{
		printf("Could not load hover enemy image");
		return false;
	}
	//srand(time(NULL));
	m_shootRate = (std::rand() %1000) + 1500;
	//printf("Hey the time generated is %i k thanks \n", m_shootRate);

	m_targetX = (rand() % Managers::GetGraphicsManager()->GetScreenWidth() - image->GetWidth()) + image->GetWidth() * 2;
	m_targetY = rand() % (Managers::GetGraphicsManager()->GetScreenHeight() - image->GetHeight());
	//printf("Hey the positions generated are X target = %i and Y target = %i\n", m_targetX, m_targetY);
	

	m_shoot.start();
	m_offsetTimer.start();
	Enemy::Init(image, x, y, 25, 2, 3);
	GetAcceleraton(m_targetX, m_targetY);
	return true;
}

void SoliderEnemy::Update(Player* playerRef)
{
	//printf("Enemy X = %f Y = %f\n", m_x, m_y);
	if (m_state == STATE::FINDING)
	{
		if (m_x>m_targetX)
		{
			m_x -= m_accelX;
			if (m_x<m_targetX)
			{
				m_x = (float)m_targetX;
			}
		}
		else
		{
			m_x += m_accelX;
			if (m_x>m_targetX)
			{
				m_x = (float)m_targetX;
			}
		}
		if (m_y>m_targetY)
		{
			m_y -= m_accelY;
			if (m_y<m_targetY)
			{
				m_y = (float)m_targetY;
			}
		}
		else
		{
			m_y += m_accelY;
			if (m_y>m_targetY)
				m_y = (float)m_targetY;
		}
		if ((std::abs(m_x - m_targetX) == 1 || std::abs(m_x - m_targetX) == 0))
		{
			if (std::abs(m_y - m_targetY) == 1 || std::abs(m_y - m_targetY) == 0)
			{
				/*Vector<Enemy> enemies = directorRef.getEnemies();
				for (int i = 0; i<enemies.size(); i++)
				{
					if (enemies.get(i).isCollidable())
					{
						if (BoundingBox.Collided(enemies.get(i).GetBoundingBox(), this.hitBox))
						{
							boolean found = false;
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
	}
	else if (m_state == STATE::FOUND)
	{
		//m_offset = (float)(std::sin(m_offsetTimer.getTicks()/100) *10);
		//printf("THe offset is %f\n", m_offset);
		if (m_shoot.getTicks() > m_shootRate)
		{
			SoliderEnemyBullet* bullet = new SoliderEnemyBullet();
			bullet->Init((int)m_x, (int)m_y + (int)m_offset + 20);
			Managers::GetBulletManager()->Add(bullet);
			m_shoot.start();
		}
	}

	m_hitbox.SetPosition((int)m_x, (int)m_y + (int)m_offset);
}
void SoliderEnemy::Draw()
{
	m_image->Render( m_x, (m_y+m_offset));
	m_healthText->Render(m_x + m_image->GetWidth() - m_healthText->GetWidth(), m_y + m_image->GetHeight() - m_healthText->GetHeight());
}
void SoliderEnemy::TakeDamage(float damage, bool fromContact)
{
	m_health -= damage;
	UpdateHealthText();
	if (m_health <= 0)
	{
		m_isDead = true;
	}
}