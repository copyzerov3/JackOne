#include "LevelSelectScreen.h"
#include "DifficultySelectScreen.h"

LevelSelectScreen::LevelSelectScreen(Managers* managerRef) :Screen(managerRef)
{
	managerRef->GetResourceManager()->GetTexture("background", &m_background);
	MakeTTFTexture("LevelSelectScreen", m_title);
}


LevelSelectScreen::~LevelSelectScreen()
{
	m_title.Free();
}

void LevelSelectScreen::Draw()
{
	SDL_Renderer* r = managers->GetGraphicsManager()->GetRenderer();
	int WIDTH = managers->GetGraphicsManager()->GetScreenWidth();
	int HEIGHT = managers->GetGraphicsManager()->GetScreenHeight();

	m_background.Render(r, 0, 0);
	m_title.Render(r, (WIDTH - m_title.GetWidth()) / 2, 0);
}

void LevelSelectScreen::Update()
{
	InputManager* i = managers->GetInputManager();

	if (i->GetQuit())
	{
		mLeave = true;
	}
	else if (i->GetEscape())
	{
		nextScreen = new DifficultySelectScreen(managers);
	}
}
