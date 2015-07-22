#include "AIDirector.h"
#include "SoliderEnemy.h"
#include "ShieldEnemy.h"
#include "SuicideBirdEnemy.h"

AIDirector::AIDirector() :m_currentStage(0), m_maxStages(0), m_spawnRate(0), m_enemies(64)
{
	switch (Managers::GetGlobalsManager()->GetDifficulty())
	{
	case GlobalsManager::DIFFICULTY::EASY:
		m_maxStages = 10;
		m_spawnRate = 14000;
		break;
	case GlobalsManager::DIFFICULTY::MEDIUM:
		m_maxStages = 15;
		m_spawnRate = 13000;
		break;
	case GlobalsManager::DIFFICULTY::HARD:
		m_maxStages = 20;
		m_spawnRate = 12000;
		break;

	}
}


AIDirector::~AIDirector()
{
	ClearAllEnemies();
}

void AIDirector::Reset(int currentLevel,GlobalsManager::AREAS area)
{
	m_level = currentLevel;
	m_area = area;
	m_currentStage = 0;
	ClearAllEnemies();
	m_spawnTimer.start();
}
void AIDirector::ClearAllEnemies()
{
	for (int i = 0; i < m_enemies.GetSize(); i++)
	{
		delete m_enemies[i];
		m_enemies[i] = nullptr;
	}
}
bool AIDirector::IsEndOfStage()
{
	return (m_enemies.GetSize() == 0 && m_currentStage == m_maxStages);
}
void AIDirector::Draw()
{
	for (int i = 0; i<m_enemies.GetSize(); i++)
	{
		m_enemies[i]->Draw();
	}
}
void AIDirector::Update(Player* player)
{
	if (m_spawnTimer.getTicks() >= m_spawnRate)
	{
		GetNextWave();
		m_spawnTimer.start();
	}
	Enemy* currentEnemy;
	for (int i = m_enemies.GetSize() - 1; i != -1; i--)
	{
		currentEnemy = m_enemies[i];
		if (!currentEnemy->IsDead())
		{
			currentEnemy->Update(player);

			if (BoundingBox::Collided(currentEnemy->GetBoundingBox(), player->GetBoundingBox()))
			{
				printf("Player collided with enemy\n");
				currentEnemy->TakeDamage(1.0f, true);
				player->TakeDamage(currentEnemy->GetContactDamage());
			}
		}
		if (currentEnemy->IsDead())
		{
			printf("Removed Dead Enemy");
			m_enemies.removePointer(i);
		}
		
	}
}
void AIDirector::GetNextWave()
{
	m_currentStage++;
	m_spawnTimer.start();
	if(m_currentStage%5 == 0)
	{
		if(m_currentStage == m_maxStages && m_level == 3)
		{
			if(m_area == GlobalsManager::AREAS::FOREST)
			{
				//enemies.add(new TorpedoTurtle(800,0,playerRef,this,false));
			}
			else if(m_area == GlobalsManager::AREAS::DESERT)
			{
				//enemies.add(new SilverCannonBack(800,0,playerRef,this,false));
			}
			else if (m_area == GlobalsManager::AREAS::CITY)
			{
				//enemies.add(new LaStatic(800,0,playerRef,this,false));
			}
			else if (m_area == GlobalsManager::AREAS::SEA)
			{
				//enemies.add(new WaterMechasin(800,0,playerRef,this,false));
			}
			else if (m_area == GlobalsManager::AREAS::SPACE)
			{
				//enemies.add(new OmniDragon(800,100,playerRef,this));
			}
		}
		else
		{
			int ran = std::rand() % 2;
			if (m_area == GlobalsManager::AREAS::FOREST)
			{
				if(ran  == 0)
				{
					//enemies.add(new Deer(800,100,playerRef,this));
				}
				else if(ran == 1)
				{
					//enemies.add(new Devil(800,200,playerRef,this));
				}
			}
			else if (m_area == GlobalsManager::AREAS::DESERT)
			{
				if(ran  == 0)
				{
					//enemies.add(new Scorpion(800,0,playerRef,this));
				}
				else if(ran == 1)
				{
					//enemies.add(new Coyote(800,0,playerRef,this));
				}
			}
			else if (m_area == GlobalsManager::AREAS::CITY)
			{
				if(ran  == 0)
				{
					ran = (std::rand() % 2) + m_level;
					for(int i =0;i<ran;i++)
					{
						int posX= 800 + 50*i + rand() % 100;
						//enemies.add(new Cop(posX,0,playerRef,this));
					}
				}
				else if(ran == 1)
				{
					int posX;
					ran = rand() % 4+m_level;
					for(int i =0;i<ran;i++)
					{
						posX= 800 + 50*i + rand() % 100;
						//enemies.add(new Rats(posX,0,playerRef,this));
					}
				}
			}
			else if (m_area == GlobalsManager::AREAS::SEA)
			{
				if(ran  == 0)
				{
					int posX;
					ran = rand() % 2 + 3;
					for(int i =0;i<ran;i++)
					{
						posX= rand() % (480 -3) + 3;
						//enemies.add(new Fish(posX,0,playerRef,this));
					}
				}
				else if(ran == 1)
				{
					//enemies.add(new Shark(300,0,playerRef,this));
				}
			}
			else if (m_area == GlobalsManager::AREAS::SPACE)
			{
				if(ran  == 0)
				{
					int posX;
					ran = rand() % (5);
					for(int i =0;i<ran;i++)
					{
						posX= 800 + 50*i;
						//enemies.add(new Meteor(posX,playerRef.GetY(),playerRef,this));
					}
				}
				else if(ran == 1)
				{
					//enemies.add(new Fighter(800,0,playerRef,this));
				}
			}

		}
	}
	else
	{
		int ran = rand() % (3);
		int pos,posx;
		if(ran  == 0)
		{
			ran = rand() %(3) + 3 + m_level;

			for(int i = 0;i<ran;i++)
			{
				posx = rand() % (100) + 800;
				pos = rand() % (1200)-400;
				SuicideBirdEnemy* enemy = new SuicideBirdEnemy();
				enemy->Init(posx, pos);
				m_enemies.push(enemy);

			}
			ran = rand()%(2);
			if(ran == 0)
			{
				ran = rand() %(2)+1+ m_level;

				for(int i =0;i<ran;i++)
				{
					pos = rand() % Managers::GetGraphicsManager()->GetScreenHeight();
					SoliderEnemy* enemy = new SoliderEnemy();
					enemy->Init(Managers::GetGraphicsManager()->GetScreenWidth() + 200, pos);
					m_enemies.push(enemy);
				}
			}
			else
			{
				ran = rand() % (1)+m_level;
				for(int i = 0;i<ran;i++)
				{
					pos = rand() % (400);
					ShieldEnemy* enemy = new ShieldEnemy();
					enemy->Init(Managers::GetGraphicsManager()->GetScreenWidth(), pos);
					m_enemies.push(enemy);
				}
			}
		}
		else if(ran == 1)
		{
			ran = rand()%(2)+1+m_level;

			for(int i =0;i<ran;i++)
			{
				pos = rand() % Managers::GetGraphicsManager()->GetScreenHeight();
				SoliderEnemy* enemy = new SoliderEnemy();
				enemy->Init(Managers::GetGraphicsManager()->GetScreenWidth() + 200, pos);
				m_enemies.push(enemy);
			}
		}
		else if(ran == 2)
		{
			ran = rand() % (2)+m_level;
			for(int i = 0;i<ran;i++)
			{
				pos = rand() % (400);
				ShieldEnemy* enemy = new ShieldEnemy();
				enemy->Init(Managers::GetGraphicsManager()->GetScreenWidth(), pos);
				m_enemies.push(enemy);
			}
		}
	}
}