#pragma once
#include "Screen.h"
#include "Timer.h"
#include "Player.h"
#include "SoliderEnemy.h"
class GameScreen :
	public Screen
{
public:
	GameScreen(GlobalsManager::AREAS area,int level);
	~GameScreen();

	bool Init();
	void Update();
	void Draw();

private:
	GlobalsManager::AREAS m_area;
	int m_level;

	Texture* m_background;
	Timer timer;
	Player *m_player;
	SoliderEnemy *m_enemy;
};

