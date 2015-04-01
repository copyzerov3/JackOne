#pragma once
#include "Screen.h"
#include "Button.h"
class LevelSelectScreen:public Screen
{
public:
	LevelSelectScreen(Managers* managersRef);
	~LevelSelectScreen();

	void Update();
	void Draw();
	bool Init();
private:
	Texture *m_forest,*m_desert,*m_city,*m_sea,*m_background,*m_space,*m_lockedTwo,*m_lockedThree,
		*m_title,*m_description;
	Button *m_levelOne, *m_levelTwo, *m_levelThree;

	int choice;
};