#pragma once
#include "Timer.h"
#include "UnorderedArray.h"
#include "Enemy.h"


class Enemy;
class AIDirector
{	
	friend class BulletManager;
	

public:
	AIDirector();
	~AIDirector();

	void Reset(int currentLevel,GlobalsManager::AREAS area);
	bool IsEndOfStage();
	void Update(Player* player);
	void Draw();
	bool AddEnemy(Enemy* enemyToAdd);
	void GetNextWave();
private:
	int m_currentStage, m_maxStages,m_spawnRate,m_level;
	Timer m_spawnTimer;
	GlobalsManager::AREAS m_area;
	UnorderedArray<Enemy*> m_enemies;
	void ClearAllEnemies();
};

