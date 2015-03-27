#include "DifficultySelectScreen.h"
#include "MainMenuScreen.h"

DifficultySelectScreen::DifficultySelectScreen(Managers* managerRef) :Screen(managerRef)
{
	managerRef->GetResourceManager()->GetTexture("background", &mBackground);
	managerRef->GetResourceManager()->GetTexture("selector", &m_selector);
	MakeTTFTexture("Difficulty Select",m_title);
	MakeTTFTexture("Easy", m_easy);
	MakeTTFTexture("Medium", m_med);
	MakeTTFTexture("Hard", m_hard);
	MakeTTFTexture("I like things super easy", m_descriptionEasy);
	MakeTTFTexture("I enjoy a challenge", m_descriptionMed);
	MakeTTFTexture("I am a sado masochist", m_descriptionHard);

	m_selectorY = 90;
	timer.start();
}

DifficultySelectScreen::~DifficultySelectScreen()
{
	m_title.Free();
	m_easy.Free();
	m_med.Free();
	m_hard.Free();
	m_descriptionEasy.Free();
	m_descriptionHard.Free();
	m_descriptionMed.Free();
	m_selectorY = 0;
}

void DifficultySelectScreen::Draw()
{
	SDL_Renderer* r = managers->GetGraphicsManager()->GetRenderer();
	int WIDTH = managers->GetGraphicsManager()->GetScreenWidth();
	int HEIGHT = managers->GetGraphicsManager()->GetScreenHeight();

	mBackground.Render(r, 0, 0);
	m_title.Render(r, (WIDTH - m_title.GetWidth()) / 2, 0);
	m_easy.Render(r, (WIDTH-m_easy.GetWidth()) / 2, 100);
	m_med.Render(r, (WIDTH-m_med.GetWidth()) / 2, 150);
	m_hard.Render(r, (WIDTH - m_hard.GetWidth()) / 2, 200);

	m_selector.Render(r, 200, m_selectorY);

	if (m_selectorY == 90)
	{
		m_descriptionEasy.Render(r, (WIDTH - m_descriptionEasy.GetWidth()) / 2, HEIGHT - m_descriptionEasy.GetHeight());
	}
	else if (m_selectorY == 140)
	{
		m_descriptionMed.Render(r, (WIDTH - m_descriptionMed.GetWidth()) / 2, HEIGHT - m_descriptionMed.GetHeight());
	}
	else if (m_selectorY == 190)
	{
		m_descriptionHard.Render(r, (WIDTH - m_descriptionHard.GetWidth()) / 2, HEIGHT - m_descriptionHard.GetHeight());
	}

}
void DifficultySelectScreen::Update()
{
	InputManager* i = managers->GetInputManager();

	if (timer.isStarted())
	{
		if (timer.getTicks() < 200)
			return;
	}
	if (i->GetUp())
	{
		timer.start();
		m_selectorY -= 50;

		if (m_selectorY == 40)
		{
			m_selectorY += 150;
		}
	}
	else if (i->GetDown())
	{
		timer.start();
		m_selectorY += 50;

		if (m_selectorY == 240)
		{
			m_selectorY -= 150;
		}
	}
	else if (managers->GetInputManager()->GetSelect() || managers->GetInputManager()->GetAttack())
	{
		if (m_selectorY == 90)
		{
			
		}
		else if (m_selectorY == 140)
		{
			
		}
		else if (m_selectorY == 190)
		{
			
		}
	}
	else if (i->GetQuit())
	{
		mLeave = true;
	}
	else if (i->GetEscape())
	{
		nextScreen = new MainMenuScreen(managers);
	}
}
