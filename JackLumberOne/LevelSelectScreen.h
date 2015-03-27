#pragma once
#include "Screen.h"
class LevelSelectScreen:public Screen
{
public:
	LevelSelectScreen(Managers* managersRef);
	~LevelSelectScreen();

	void Update();
	void Draw();

private:
	Texture m_background,
		m_title;
};