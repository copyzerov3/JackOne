#include "LevelSelectScreen.h"
#include "DifficultySelectScreen.h"

LevelSelectScreen::LevelSelectScreen(Managers* managerRef) :Screen(managerRef)
{
	choice = 1;
}
bool LevelSelectScreen::Init()
{
	ResourceManager* r = managers->GetResourceManager();
	if(!r->GetTexture("Background", m_background))
		return false;
	if (!r->GetTexture("CityAreaBackground", m_city))
		return false;

	if (!r->GetTexture("DesertAreaBackground", m_desert))
		return false;

	if (!r->GetTexture("ForestAreaBackground", m_forest))
		return false;

	if (!r->GetTexture("SeaAreaBackground", m_sea))
		return false;

	if (!r->GetTexture("SpaceAreaBackground", m_space))
		return false;

	if (!r->GetTexture("LevelTwoLocked", m_lockedTwo))
		return false;

	if (!r->GetTexture("LevelThreeLocked", m_lockedThree))
		return false;

	m_levelOne = new Button();
	m_levelTwo = new Button();
	m_levelThree = new Button();

	m_levelOne->Init("LevelOneButton", r);
	m_levelTwo->Init("LevelTwoButton", r);
	m_levelThree->Init("LevelThreeButton", r);

	MakeTTFTexture("Forest", m_title);

	return true;
}

LevelSelectScreen::~LevelSelectScreen()
{
	delete m_title;
	delete m_description;
	delete m_levelOne;
	delete m_levelTwo;
	delete m_levelThree;
}

void LevelSelectScreen::Draw()
{
	SDL_Renderer* r = managers->GetGraphicsManager()->GetRenderer();
	int WIDTH = managers->GetGraphicsManager()->GetScreenWidth();
	int HEIGHT = managers->GetGraphicsManager()->GetScreenHeight();
	switch (choice)
	{
	case 1:
		m_forest->Render(r, 0, 0);
		break;
	case 2:
		m_desert->Render(r, 0, 0);
		break;
	case 3:
		m_city->Render(r, 0, 0);
		break;
	case 4:
		m_sea->Render(r, 0, 0);
		break;
	case 5:
		m_space->Render(r, 0, 0);
		break;
	}
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
