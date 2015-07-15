#pragma once
#include "Screen.h"
#include "Button.h"
#include "Timer.h"
class LevelSelectScreen:public Screen
{
public:
	LevelSelectScreen();
	~LevelSelectScreen();

	void Update();
	void Draw();
	bool Init();
private:
	Texture *m_forestLevelOne,
		*m_forestLevelTwo,
		*m_forestLevelThree,
		*m_desertLevelOne,
		*m_desertLevelTwo,
		*m_desertLevelThree,
		*m_cityLevelOne,
		*m_cityLevelTwo,
		*m_cityLevelThree,
		*m_seaLevelOne,
		*m_seaLevelTwo,
		*m_seaLevelThree,
		*m_spaceLevelOne,
		*m_spaceLevelTwo,
		*m_spaceLevelThree;

	int choice,choiceLevel;
	int max;
	Timer timer;
	void DrawForest();
	void DrawDesert();
	void DrawCity();
	void DrawSea();
	void DrawSpace();
	void CheckChoice();

};