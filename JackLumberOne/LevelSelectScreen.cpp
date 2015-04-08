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

	if (!m_levelOne->Init("LevelOne", r))
		return false;
	if (!m_levelTwo->Init("LevelTwo", r))
		return false;
	if (!m_levelThree->Init("LevelThree", r))
		return false;

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
	GlobalsManager* g = managers->GetGlobalsManager();
	m_forest->Render(r, 0, 0);

	if (g->IsForestTwoUnlocked())
	{
		m_levelTwo->Render(r);
	}
	else
	{
		m_lockedTwo->Render(r, 0 * scaleMode, 0 * scaleMode);
	}
	if (g->IsForestThreeUnlocked())
	{
		m_levelThree->Render(r);
	}
	else
	{
		m_lockedThree->Render(r, 0 * scaleMode, 0 * scaleMode);
	}
}
void LevelSelectScreen::DrawDesert()
{
	GlobalsManager* g = managers->GetGlobalsManager();
	m_desert->Render(r, 0, 0);
	if (g->IsDesertTwoUnlocked())
	{
		m_levelTwo->Render(r);
	}
	else
	{
		m_lockedTwo->Render(r, 0 * scaleMode, 0 * scaleMode);
	}
	if (g->IsDesertThreeUnlocked())
	{
		m_levelThree->Render(r);
	}
	else
	{
		m_lockedThree->Render(r, 0 * scaleMode, 0 * scaleMode);
	}
}
void LevelSelectScreen::DrawCity()
{
	GlobalsManager* g = managers->GetGlobalsManager();
	m_city->Render(r, 0, 0);

	if (g->IsCityTwoUnlocked())
	{
		m_levelTwo->Render(r);
	}
	else
	{
		m_lockedTwo->Render(r, 0 * scaleMode, 0 * scaleMode);
	}
	if (g->IsCityThreeUnlocked())
	{
		m_levelThree->Render(r);
	}
	else
	{
		m_lockedThree->Render(r, 0 * scaleMode, 0 * scaleMode);
	}
}
void LevelSelectScreen::DrawSea()
{
	GlobalsManager* g = managers->GetGlobalsManager();
	m_sea->Render(r, 0, 0);
	if (g->IsSeaTwoUnlocked())
	{
		m_levelTwo->Render(r);
	}
	else
	{
		m_lockedTwo->Render(r, 0 * scaleMode, 0 * scaleMode);
	}
	if (g->IsSeaThreeUnlocked())
	{
		m_levelThree->Render(r);
	}
	else
	{
		m_lockedThree->Render(r, 0 * scaleMode, 0 * scaleMode);
	}
}
void LevelSelectScreen::DrawSpace()
{
	GlobalsManager* g = managers->GetGlobalsManager();
	m_space->Render(r, 0, 0);

	if (g->IsSpaceTwoUnlocked())
	{
		m_levelTwo->Render(r);
	}
	else
	{
		m_lockedTwo->Render(r, 0 * scaleMode, 0 * scaleMode);
	}
	if (g->IsSpaceThreeUnlocked())
	{
		m_levelThree->Render(r);
	}
	else
	{
		m_lockedThree->Render(r, 0 * scaleMode, 0 * scaleMode);
	}
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
	m_levelOne->Render(r);
}
void LevelSelectScreen::SetChoice()
{
	GlobalsManager* g = managers->GetGlobalsManager();
	switch (choice)
	{
	case 1:
		MakeTTFTexture("Forest", m_title);
		if (g->IsForestTwoUnlocked())
		{
			m_levelTwo->SetPosition(0*scaleMode,0*scaleMode);
		}
		if (g->IsForestThreeUnlocked())
		{
			m_levelThree->SetPosition(0 * scaleMode, 0 * scaleMode);
		}
		break;
	case 2:
		MakeTTFTexture("Desert", m_title);
		if (g->IsDesertTwoUnlocked())
		{
			m_levelTwo->SetPosition(0 * scaleMode, 0 * scaleMode);
		}
		if (g->IsDesertThreeUnlocked())
		{
			m_levelThree->SetPosition(0 * scaleMode, 0 * scaleMode);
		}
		break;
	case 3:
		MakeTTFTexture("City", m_title);
		if (g->IsCityTwoUnlocked())
		{
			m_levelTwo->SetPosition(0 * scaleMode, 0 * scaleMode);
		}
		if (g->IsCityThreeUnlocked())
		{
			m_levelThree->SetPosition(0 * scaleMode, 0 * scaleMode);
		}
		break;
	case 4:
		MakeTTFTexture("Sea", m_title);
		if (g->IsSeaTwoUnlocked())
		{
			m_levelTwo->SetPosition(0 * scaleMode, 0 * scaleMode);
		}
		if (g->IsSeaThreeUnlocked())
		{
			m_levelThree->SetPosition(0 * scaleMode, 0 * scaleMode);
		}
		break;
	case 5:
		MakeTTFTexture("Space", m_title);
		if (g->IsSpaceTwoUnlocked())
		{
			m_levelTwo->SetPosition(0 * scaleMode, 0 * scaleMode);
		}
		if (g->IsSpaceThreeUnlocked())
		{
			m_levelThree->SetPosition(0 * scaleMode, 0 * scaleMode);
		}
		break;
	}
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

		SetChoice();
	}
	if (im->GetUp())
	{
		choice--;
		timer.start();
		if (choice == 0)
			choice = max - 1;

		SetChoice();
	}
}
