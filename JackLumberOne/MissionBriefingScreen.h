#pragma once
#include "Screen.h"
#include "Button.h"
#include "Timer.h"
class MissionBriefingScreen:public Screen
{
public:
	MissionBriefingScreen(GlobalsManager::AREAS area,int level);
	~MissionBriefingScreen();

	void Update();
	void Draw();
	bool Init();

private:
	Texture *m_background, *m_selector,*m_title;

	Button *m_shop, *m_play;
	Timer m_timer;
	GlobalsManager::AREAS m_area;
	int m_level;
	int choice;
};

