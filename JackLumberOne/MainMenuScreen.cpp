#include "MainMenuScreen.h"
#include "SettingsScreen.h"
#include "DifficultySelectScreen.h"

MainMenuScreen::MainMenuScreen(Managers* managerRef) :Screen(managerRef)
{
	
}
bool MainMenuScreen::Init()
{
	if(!managers->GetResourceManager()->GetTexture("Background", mBackground))
		return false;
	if(!managers->GetResourceManager()->GetTexture("menuSelector", mSelector))
		return false;

	m_exit = new Button();
	if (!m_exit->Init("ExitButton", managers->GetResourceManager()))
		return false;

	m_play = new Button();
	if (!m_play->Init("PlayButton", managers->GetResourceManager()))
		return false;

	m_settings = new Button();
	if (!m_settings->Init("SettingsButton", managers->GetResourceManager()))
		return false;

	MakeTTFTexture("Title", m_title);
	choice = 1;
	timer.start();
	m_play->SetIsSelected(true);

	int WIDTH = managers->GetGraphicsManager()->GetScreenWidth();
	int HEIGHT = managers->GetGraphicsManager()->GetScreenHeight();
	int mid = (HEIGHT + m_title->GetHeight() - m_settings->GetHeight()) / 2;

	m_play->SetPosition((WIDTH - m_play->GetWidth()) / 2, (mid) / 2);
	m_settings->SetPosition((WIDTH - m_settings->GetWidth()) / 2, mid);
	m_exit->SetPosition((WIDTH - m_exit->GetWidth()) / 2, mid + (mid / 2));
	return true;
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
	mBackground->Render(r, 0, 0);
	m_play->Render(r);
	m_settings->Render(r);
	m_exit->Render(r);
	
	m_title->Render(r, (WIDTH - m_title->GetWidth()) / 2, 0);
	int pos = 0,posX = 0;
	
	switch (choice)
	{
	case 1:
		pos = m_play->GetY() + ((unsigned int(m_play->GetHeight() - mSelector->GetHeight())) / 2);
		posX = m_play->GetX() - mSelector->GetWidth();
		break;
	case 2:
		pos = m_settings->GetY() + ((unsigned int(m_settings->GetHeight() - mSelector->GetHeight())) / 2);
		posX = m_settings->GetX() - mSelector->GetWidth();
		break;
	case 3:
		pos = m_exit->GetY() + ((unsigned int(m_exit->GetHeight() - mSelector->GetHeight())) / 2);
		posX = m_exit->GetX() - mSelector->GetWidth();
		break;
	}
	mSelector->Render(r,posX , pos);
}

void MainMenuScreen::Update()
{
	if (timer.isStarted())
	{
		if (timer.getTicks() < 200)
			return;
	}
	if (im->GetUp())
	{
		timer.start();
		choice--;
		if (choice == 0)
		{
			choice = 3;
		}
	}
	else if (im->GetDown())
	{
		timer.start();
		choice++;
		if (choice == 4)
		{
			choice = 1;
		}
	}
	else if (im->GetSelect() || im->GetAttack())
	{
		if (choice ==1)
		{
			nextScreen = new DifficultySelectScreen(managers);
		}
		else if (choice == 2)
		{
			nextScreen = new SettingsScreen(managers);
		}
		else if (choice == 3)
		{
			mLeave = true;
		}
	}
	else if (im->GetEscape() || im->GetQuit())
	{
		mLeave = true;
	}
	if (choice == 1)
	{
		m_play->SetIsSelected(true);
	}
	else
	{
		m_play->SetIsSelected(false);
	}
	if (choice == 2)
	{
		m_settings->SetIsSelected(true);
	}
	else
	{
		m_settings->SetIsSelected(false);
	}
	if (choice== 3)
	{
		m_exit->SetIsSelected(true);
	}
	else
	{
		m_exit->SetIsSelected(false);
	}
	
	
}
