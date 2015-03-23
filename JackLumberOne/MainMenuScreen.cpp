#include "MainMenuScreen.h"
#include "SettingsScreen.h"

MainMenuScreen::MainMenuScreen(Managers* managerRef) :Screen(managerRef)
{
	managerRef->GetResourceManager()->GetTexture("background", &mBackground);
	managerRef->GetResourceManager()->GetTexture("selector", &mSelector);
	MakeTTFTexture("Exit", m_exit);
	MakeTTFTexture("Play", m_play);
	MakeTTFTexture("Settings", m_settings);
	MakeTTFTexture("Title", m_title);
	selectorY = 260;
}


MainMenuScreen::~MainMenuScreen()
{
}

void MainMenuScreen::Draw()
{
	SDL_Renderer* g = managers->GetGraphicsManager()->GetRenderer();
	mBackground.Render(g, 0, 0);
	m_exit.Render(g, (1920 - m_exit.GetWidth()) / 2, 1080 - 400);
	m_settings.Render(g, (1920 - m_settings.GetWidth()) / 2, 1080 - 600);
	m_play.Render(g, (1920 - m_play.GetWidth()) / 2, 1080 - 800);
	m_title.Render(g, (1920 - m_title.GetWidth()) / 2, 100);
	mSelector.Render(g, 200, selectorY);
}

void MainMenuScreen::Update()
{
	if (timer.isStarted())
	{
		if (timer.getTicks() < 200)
			return;
	}
	if (managers->GetInputManager()->GetUp())
	{
		timer.start();
		selectorY -= 50;
		if (selectorY < 240)
		{
			selectorY += 150;
		}
	}
	else if (managers->GetInputManager()->GetDown())
	{
		timer.start();
		selectorY += 50;
		if (selectorY > 400)
		{
			selectorY -= 150;
		}
	}
	else if (managers->GetInputManager()->GetSelect() || managers->GetInputManager()->GetAttack())
	{
		if (selectorY == 260)
		{
			//Go to level select;
		}
		else if (selectorY == 310)
		{
			nextScreen = new SettingsScreen(managers);
		}
		else if (selectorY == 360)
		{
			mLeave = true;
		}
	}
	else if (managers->GetInputManager()->GetEscape())
	{
		mLeave = true;
	}
}
