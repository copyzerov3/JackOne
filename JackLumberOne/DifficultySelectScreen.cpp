#include "DifficultySelectScreen.h"
#include "MainMenuScreen.h"

DifficultySelectScreen::DifficultySelectScreen(Managers* managerRef) :Screen(managerRef)
{
	managerRef->GetResourceManager()->GetTexture("background", &mBackground);
	managerRef->GetResourceManager()->GetTexture("selector", &m_selector);
	MakeTTFTexture("Difficulty Select",m_title);
	MakeTTFTexture("Easy", m_easy);
	MakeTTFTexture("Medium,", m_med);
	MakeTTFTexture("Hard", m_hard);
	MakeTTFTexture("I like things super easy", m_descriptionEasy);
	MakeTTFTexture("I enjoy a challenge", m_descriptionMed);
	MakeTTFTexture("I am a sadomasochist", m_descriptionHard);
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
	

}
void DifficultySelectScreen::Update()
{
	InputManager* i = managers->GetInputManager();

	if (i->GetQuit())
	{
		mLeave = true;
	}
	else if (i->GetEscape())
	{
		nextScreen = new MainMenuScreen(managers);
	}
}
