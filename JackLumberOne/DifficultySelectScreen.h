#pragma once
#include "Screen.h"
#include "Timer.h"
#include "Button.h"
class DifficultySelectScreen:public Screen
{
public:
	DifficultySelectScreen(Managers* managerRef);
	~DifficultySelectScreen();

	void Update();
	void Draw();
	bool Init();
private:
	Texture *mBackground,
		*m_title,
		*m_descriptionEasy,
		*m_descriptionMed,
		*m_descriptionHard,
		*m_selector;
	Button *m_easy, *m_med, *m_hard;

	int choice;
	Timer timer;
};

