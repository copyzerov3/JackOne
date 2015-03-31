#include "LevelSelectScreen.h"
#include "DifficultySelectScreen.h"

LevelSelectScreen::LevelSelectScreen(Managers* managerRef) :Screen(managerRef)
{
	
}
bool LevelSelectScreen::Init()
{
	m_background = managers->GetResourceManager()->GetTexture("Background", m_background);
	if (m_background == nullptr)
		return false;
	m_title = new Texture();
	MakeTTFTexture("Level Select Screen", m_title);

	return true;
}

LevelSelectScreen::~LevelSelectScreen()
{
	delete m_title;
}

void LevelSelectScreen::Draw()
{
	SDL_Renderer* r = managers->GetGraphicsManager()->GetRenderer();
	int WIDTH = managers->GetGraphicsManager()->GetScreenWidth();
	int HEIGHT = managers->GetGraphicsManager()->GetScreenHeight();

	m_background->Render(r, 0, 0);
	m_title->Render(r, (WIDTH - m_title->GetWidth()) / 2, 0);
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
