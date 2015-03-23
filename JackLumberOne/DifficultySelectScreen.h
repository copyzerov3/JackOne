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
	Texture mBackground,
		m_title,
		m_descriptionEasy,
		m_descriptionMed,
		m_descriptionHard,
		m_selector,
		m_easy,
		m_med,
		m_hard;
};

