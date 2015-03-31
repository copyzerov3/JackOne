#include "MainMenuScreen.h"
#include "SettingsScreen.h"
#include "DifficultySelectScreen.h"

MainMenuScreen::MainMenuScreen(Managers* managerRef) :Screen(managerRef)
{
	
}
void MainMenuScreen::Init()
{
	mBackground = managers->GetResourceManager()->GetTexture("Background", mBackground);
	mSelector = managers->GetResourceManager()->GetTexture("menuSelector", mSelector);
	m_exit = new Button("ExitButton", managers->GetResourceManager());
	m_play = new Button("PlayButton", managers->GetResourceManager());
	m_settings = new Button("SettingsButton", managers->GetResourceManager());
	m_title = new Texture();
	MakeTTFTexture("Title", m_title);
	selectorY = 260;
	timer.start();
	m_play->SetIsSelected(true);
}

MainMenuScreen::~MainMenuScreen()
{
	delete m_exit;
	delete m_play;
	delete m_settings;
	delete m_title;

}

void MainMenuScreen::Draw()
{
	
	SDL_Renderer* g = managers->GetGraphicsManager()->GetRenderer();

	int WIDTH = managers->GetGraphicsManager()->GetScreenWidth();
	int HEIGHT = managers->GetGraphicsManager()->GetScreenHeight();
	mBackground->Render(g, 0, 0);
	int mid = (HEIGHT + m_title->GetHeight() - m_settings->GetHeight()) / 2;
	m_play->Render(g, (WIDTH - m_play->GetWidth()) / 2, (mid)/2);
	m_settings->Render(g, (WIDTH - m_settings->GetWidth()) / 2, mid);
	m_exit->Render(g, (WIDTH - m_exit->GetWidth()) / 2, mid +(mid/2));
	
	m_title->Render(g, (WIDTH - m_title->GetWidth()) / 2, 0);
	
	mSelector->Render(g, 200, selectorY);
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
			nextScreen = new DifficultySelectScreen(managers);
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
	if (selectorY == 260)
	{
		m_play->SetIsSelected(true);
	}
	else
	{
		m_play->SetIsSelected(false);
	}
	if (selectorY == 310)
	{
		m_settings->SetIsSelected(true);
	}
	else
	{
		m_settings->SetIsSelected(false);
	}
	if (selectorY == 360)
	{
		m_exit->SetIsSelected(true);
	}
	else
	{
		m_exit->SetIsSelected(false);
	}
	
	
}
