#pragma once
#include "Enemy.h"
class ShieldEnemy :
	public Enemy
{
public:
	ShieldEnemy();
	~ShieldEnemy();
	bool Init(int x, int y);
	void Update(Player* playerRef);
	void Draw();
	void TakeDamage(float damage, bool fromContact);
private:
	enum STATE{
		FINDING,FOUND
	};

	STATE m_state;
	float m_offset;
	int m_targetX, m_targetY;
};

