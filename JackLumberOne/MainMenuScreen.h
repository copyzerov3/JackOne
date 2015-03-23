#pragma once
#include "Screen.h"
#include "Timer.h"
class MainMenuScreen :
	public Screen
{
public:
	MainMenuScreen(Managers* managerRef);
	~MainMenuScreen();

	void Update();
	void Draw();
private:
	Texture mBackground;
	Texture mSelector;
	Texture m_title;
	Texture m_play;
	Texture m_settings;
	Texture m_exit;
	int selectorY;
	Timer timer;
};

