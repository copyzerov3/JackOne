#pragma once
#include "Enemy.h"
#include "Timer.h"
class SoliderEnemy :
	public Enemy
{
public:
	SoliderEnemy();
	~SoliderEnemy();
	bool Init(int x, int y);
	void Update(Player* playerRef);
	void Draw();
	void TakeDamage(float damage, bool fromContact);
private:
	
	enum STATE
	{
		FINDING, FOUND
	};
	STATE m_state;
	Timer m_shoot,m_offsetTimer;
	float m_offset,m_time;
	int m_targetX, m_targetY;
	unsigned int m_shootRate;
};

