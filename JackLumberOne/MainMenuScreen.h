#pragma once
#include "Screen.h"
#include "Timer.h"
#include "Button.h"
class MainMenuScreen :
	public Screen
{
public:
	MainMenuScreen(Managers* managerRef);
	~MainMenuScreen();

	void Update();
	void Draw();
private:
	Texture* mBackground;
	Texture* mSelector;
	Texture* m_title;
	Button* m_play;
	Button* m_settings;
	Button* m_exit;
	int selectorY;
	Timer timer;
};

