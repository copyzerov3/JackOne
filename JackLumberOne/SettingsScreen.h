#pragma once
#include "Screen.h"
class SettingsScreen :
	public Screen
{
public:
	SettingsScreen(Managers* managerRef);
	~SettingsScreen();

	void Update();
	void Draw();
	void Init();
private:
	Texture* m_background;
	Texture* m_title;
};

