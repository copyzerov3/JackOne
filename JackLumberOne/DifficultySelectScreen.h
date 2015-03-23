#pragma once
#include "Screen.h"
class DifficultySelectScreen:public Screen
{
public:
	DifficultySelectScreen(Managers* managerRef);
	~DifficultySelectScreen();

	void Update();
	void Draw();

private:
	Texture mBackground;
};

