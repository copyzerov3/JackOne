#include "DifficultySelectScreen.h"
#include "MainMenuScreen.h"
#include "LevelSelectScreen.h"
DifficultySelectScreen::DifficultySelectScreen()
{
	
}

bool DifficultySelectScreen::Init()
{
	if(!Managers::GetResourceManager()->GetTexture("Background", mBackground))
		return false;
	if (!Managers::GetResourceManager()->GetTexture("menuSelector", m_selector))
		return false;
	MakeTTFTexture("Difficulty Select",m_title);
	MakeTTFTexture("I like things super easy", m_descriptionEasy);
	MakeTTFTexture("I enjoy a challenge", m_descriptionMed);
	MakeTTFTexture("I am a sado masochist", m_descriptionHard);

	m_easy = new Button();
	if (!m_easy->Init("EasyButton"))
		return false;
	m_med = new Button();
	if (!m_med->Init("MediumButton"))
		return false;
	m_hard = new Button();
	if (!m_hard->Init("HardButton"))
		return false;

	int WIDTH = Managers::GetGraphicsManager()->GetScreenWidth();
	int HEIGHT = Managers::GetGraphicsManager()->GetScreenHeight();

	m_easy->SetPosition((WIDTH - m_easy->GetWidth()) / 2, 100);
	m_med->SetPosition((WIDTH - m_med->GetWidth()) / 2, 200);
	m_hard->SetPosition((WIDTH - m_hard->GetWidth()) / 2, 300);

	m_easy->SetIsSelected(true);

	choice = 1;
	timer.start();

	return true;
}

DifficultySelectScreen::~DifficultySelectScreen()
{
	delete m_title;
	delete m_easy;
	delete m_med;
	delete m_hard;
	delete m_descriptionEasy;
	delete m_descriptionHard;
	delete m_descriptionMed;
	mBackground = nullptr;
	m_selector = nullptr;
	choice = 0;
}

void DifficultySelectScreen::Draw()
{
	mBackground->Render(r, 0, 0);
	m_title->Render(r, (WIDTH - m_title->GetWidth()) / 2, 0);
	m_easy->Render(r);
	m_med->Render(r);
	m_hard->Render(r);

	int posX = 0, posY = 0;

	switch (choice)
	{
	case 1:
		m_descriptionEasy->Render(r, (WIDTH - m_descriptionEasy->GetWidth()) / 2, HEIGHT - m_descriptionEasy->GetHeight());
		posY = m_easy->GetY() + ((unsigned int(m_easy->GetHeight() - m_selector->GetHeight())) / 2);
		posX = m_easy->GetX() - m_selector->GetWidth();
		break;
	case 2:
		m_descriptionMed->Render(r, (WIDTH - m_descriptionMed->GetWidth()) / 2, HEIGHT - m_descriptionMed->GetHeight());
		posY = m_med->GetY() + ((unsigned int(m_med->GetHeight() - m_selector->GetHeight())) / 2);
		posX = m_med->GetX() - m_selector->GetWidth();
		break;
	case 3:
		m_descriptionHard->Render(r, (WIDTH - m_descriptionHard->GetWidth()) / 2, HEIGHT - m_descriptionHard->GetHeight());
		posY = m_hard->GetY() + ((unsigned int(m_hard->GetHeight() - m_selector->GetHeight())) / 2);
		posX = m_hard->GetX() - m_selector->GetWidth();
		break;
	}

	m_selector->Render(r, posX,posY);
}
void DifficultySelectScreen::Update()
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
	else if (im->GetEnter() || im->GetAttack() || im->GetA())
	{
		GlobalsManager* g = Managers::GetGlobalsManager();
		if (choice == 1)
		{
			g->SetDifficulty(g->EASY);
		}
		else if (choice == 2)
		{
			g->SetDifficulty(g->MEDIUM);
		}
		else if (choice == 3)
		{
			g->SetDifficulty(g->HARD);
		}
		nextScreen = new LevelSelectScreen();
	}
	else if (im->GetQuit())
	{
		mLeave = true;
	}
	else if (im->GetEscape() || im->GetX())
	{
		nextScreen = new MainMenuScreen();
	}
	if (choice == 1)
	{
		m_easy->SetIsSelected(true);
	}
	else
	{
		m_easy->SetIsSelected(false);
	}
	if (choice == 2)
	{
		m_med->SetIsSelected(true);
	}
	else
	{
		m_med->SetIsSelected(false);
	}
	if (choice == 3)
	{
		m_hard->SetIsSelected(true);
	}
	else
	{
		m_hard->SetIsSelected(false);
	}

}
