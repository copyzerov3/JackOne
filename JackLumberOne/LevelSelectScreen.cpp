#include "LevelSelectScreen.h"
#include "DifficultySelectScreen.h"

LevelSelectScreen::LevelSelectScreen(Managers* managerRef) :Screen(managerRef)
{
	choice = 1;
	if (managers->GetGlobalsManager()->IsSpaceUnlocked())
		max = 5;
	else
		max = 6;
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

	timer.start();
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
void LevelSelectScreen::DrawForest()
{
	m_forest->Render(r, 0, 0);
	MakeTTFTexture("Forest", m_title);
}
void LevelSelectScreen::DrawDesert()
{
	m_desert->Render(r, 0, 0);
	MakeTTFTexture("Desert", m_title);
}
void LevelSelectScreen::DrawCity()
{
	m_city->Render(r, 0, 0);
	MakeTTFTexture("City", m_title);
}
void LevelSelectScreen::DrawSea()
{
	m_sea->Render(r, 0, 0);
	MakeTTFTexture("Sea", m_title);
}
void LevelSelectScreen::DrawSpace()
{
	m_space->Render(r, 0, 0);
	MakeTTFTexture("Space", m_title);
}
void LevelSelectScreen::Draw()
{
	switch (choice)
	{
	case 1:
		DrawForest();
		break;
	case 2:
		DrawDesert();
		break;
	case 3:
		DrawCity();
		break;
	case 4:
		DrawSea();
		break;
	case 5:
		DrawSpace();
		break;
	}
	m_title->Render(r, (WIDTH - m_title->GetWidth()) / 2, 0);
}

void LevelSelectScreen::Update()
{
	if (timer.isStarted())
	{
		if (timer.getTicks() < 200)
			return;
	}
	if (im->GetQuit())
	{
		mLeave = true;
	}
	if (im->GetEscape())
	{
		nextScreen = new DifficultySelectScreen(managers);
	}
	if (im->GetDown())
	{
		choice++;
		timer.start();
		if (choice == max)
			choice = 1;
	}
	if (im->GetUp())
	{
		choice--;
		timer.start();
		if (choice == 0)
			choice = max - 1;
	}
}
