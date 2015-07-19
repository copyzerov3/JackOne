#pragma once
#include "Enemy.h"
class SuicideBirdEnemy :
	public Enemy
{
public:
	SuicideBirdEnemy();
	~SuicideBirdEnemy();
	bool Init(int x, int y);
	void Update(Player* playerRef);
	void Draw();
private:
	enum STATE{
		TARGETING,ATTACKING
	};
	STATE m_state;
	float m_offset;
};

