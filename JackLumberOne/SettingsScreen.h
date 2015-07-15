#pragma once
#include "Screen.h"
class SettingsScreen :
	public Screen
{
public:
	SettingsScreen();
	~SettingsScreen();

	void Update();
	void Draw();
	bool Init();
private:
	Texture* m_background;
	Texture* m_title;
};

