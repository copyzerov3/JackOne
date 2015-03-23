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
	timer.start();
}


MainMenuScreen::~MainMenuScreen()
{
	m_exit.Free();
	m_play.Free();
	m_settings.Free();
	m_title.Free();

}

void MainMenuScreen::Draw()
{
	
	SDL_Renderer* g = managers->GetGraphicsManager()->GetRenderer();

	int WIDTH = managers->GetGraphicsManager()->GetScreenWidth();
	int HEIGHT = managers->GetGraphicsManager()->GetScreenHeight();
	mBackground.Render(g, 0, 0);
	m_play.Render(g, (WIDTH - m_play.GetWidth()) / 2, 270);
	m_settings.Render(g, (WIDTH - m_settings.GetWidth()) / 2,  320);
	m_exit.Render(g, (WIDTH - m_exit.GetWidth()) / 2, 370);
	m_title.Render(g, (WIDTH - m_title.GetWidth()) / 2, 0);
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
	else if (managers->GetInputManager()->GetEscape() || managers->GetInputManager()->GetQuit())
	{
		mLeave = true;
	}
}
