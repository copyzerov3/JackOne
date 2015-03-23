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
private:
	Texture m_background;
};

