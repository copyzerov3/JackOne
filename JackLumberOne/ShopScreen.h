#pragma once
#include "Screen.h"
#include "Timer.h"
#include "MissionBriefingScreen.h"
class ShopScreen :
	public Screen
{
public:
	ShopScreen(Managers* managers,MissionBriefingScreen* screen);
	~ShopScreen();

	bool Init();
	void Draw();
	void Update();

private:
	Texture *m_background,*m_title;
	MissionBriefingScreen* m_prevScreen;
	Timer timer;
};

