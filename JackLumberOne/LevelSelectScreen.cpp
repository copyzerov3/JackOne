#include "LevelSelectScreen.h"
#include "DifficultySelectScreen.h"
#include "MissionBriefingScreen.h"
LevelSelectScreen::LevelSelectScreen(Managers* managerRef) :Screen(managerRef)
{
	choice = 1;
	if (!managers->GetGlobalsManager()->IsSpaceUnlocked())
		max = 5;
	else
		max = 6;
	choiceLevel = 1;
}
bool LevelSelectScreen::Init()
{
	ResourceManager* r = managers->GetResourceManager();
	if(!r->GetTexture("ForestLevelOneBackground", m_forestLevelOne))
		return false;
	if (!r->GetTexture("ForestLevelTwoBackground", m_forestLevelTwo))
		return false;
	if (!r->GetTexture("ForestLevelThreeBackground", m_forestLevelThree))
		return false;

	if (!r->GetTexture("CityLevelOneBackground", m_cityLevelOne))
		return false;
	if (!r->GetTexture("CityLevelTwoBackground", m_cityLevelTwo))
		return false;
	if (!r->GetTexture("CityLevelThreeBackground", m_cityLevelThree))
		return false;

	if (!r->GetTexture("DesertLevelOneBackground", m_desertLevelOne))
		return false;
	if (!r->GetTexture("DesertLevelTwoBackground", m_desertLevelTwo))
		return false;
	if (!r->GetTexture("DesertLevelThreeBackground", m_desertLevelThree))
		return false;

	if (!r->GetTexture("SeaLevelOneBackground", m_seaLevelOne))
		return false;
	if (!r->GetTexture("SeaLevelTwoBackground", m_seaLevelTwo))
		return false;
	if (!r->GetTexture("SeaLevelThreeBackground", m_seaLevelThree))
		return false;

	if (!r->GetTexture("SpaceLevelOneBackground", m_spaceLevelOne))
		return false;
	if (!r->GetTexture("SpaceLevelTwoBackground", m_spaceLevelTwo))
		return false;
	if (!r->GetTexture("SpaceLevelThreeBackground", m_spaceLevelThree))
		return false;

	timer.start();
	return true;
}

LevelSelectScreen::~LevelSelectScreen()
{
}
void LevelSelectScreen::DrawForest()
{
	switch (choiceLevel)
	{
	case 1:
		m_forestLevelOne->Render(r,0, 0);
		break;
	case 2:
		m_forestLevelTwo->Render(r,0, 0);
		break;
	case 3:
		m_forestLevelThree->Render(r, 0, 0);
		break;
	}
}
void LevelSelectScreen::DrawDesert()
{
	switch (choiceLevel)
	{
	case 1:
		m_desertLevelOne->Render(r, 0, 0);
		break;
	case 2:
		m_desertLevelTwo->Render(r, 0, 0);
		break;
	case 3:
		m_desertLevelThree->Render(r, 0, 0);
		break;
	}
}
void LevelSelectScreen::DrawCity()
{
	switch (choiceLevel)
	{
	case 1:
		m_cityLevelOne->Render(r, 0, 0);
		break;
	case 2:
		m_cityLevelTwo->Render(r, 0, 0);
		break;
	case 3:
		m_cityLevelThree->Render(r, 0, 0);
		break;
	}
}
void LevelSelectScreen::DrawSea()
{
	switch (choiceLevel)
	{
	case 1:
		m_seaLevelOne->Render(r, 0, 0);
		break;
	case 2:
		m_seaLevelTwo->Render(r, 0, 0);
		break;
	case 3:
		m_seaLevelThree->Render(r, 0, 0);
		break;
	}
}
void LevelSelectScreen::DrawSpace()
{
	switch (choiceLevel)
	{
	case 1:
		m_spaceLevelOne->Render(r, 0, 0);
		break;
	case 2:
		m_spaceLevelTwo->Render(r, 0, 0);
		break;
	case 3:
		m_spaceLevelThree->Render(r, 0, 0);
		break;
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
}
void LevelSelectScreen::CheckChoice()
{
	GlobalsManager* g = managers->GetGlobalsManager();
	GlobalsManager::AREAS area;
	switch (choice)
	{
		case 1:
			area = GlobalsManager::FOREST;
		if (!g->IsForestTwoUnlocked() && choiceLevel == 2)
		{
			return;
		}
		else if (!g->IsForestThreeUnlocked() && choiceLevel == 3)
		{
			return;
		}
		break;
	case 2:
		area = GlobalsManager::DESERT;
		if (!g->IsDesertTwoUnlocked() && choiceLevel == 2)
		{
			return;
		}
		else if (!g->IsDesertThreeUnlocked() && choiceLevel == 3)
		{
			return;
		}
		break;
	case 3:
		area = GlobalsManager::CITY;
		if (!g->IsCityTwoUnlocked() && choiceLevel == 2)
		{
			return;
		}
		else if (!g->IsCityThreeUnlocked() && choiceLevel == 3)
		{
			return;
		}
		break;
	case 4:
		area = GlobalsManager::SEA;
		if (!g->IsSeaTwoUnlocked() && choiceLevel == 2)
		{
			return;
		}
		else if (!g->IsSeaThreeUnlocked() && choiceLevel == 3)
		{
			return;
		}
		break;
	case 5:
		area = GlobalsManager::SPACE;
		if (!g->IsSpaceTwoUnlocked() && choiceLevel == 2)
		{
			return;
		}
		else if (!g->IsSpaceThreeUnlocked() && choiceLevel == 3)
		{
			return;
		}
		break;
	}
	nextScreen = new MissionBriefingScreen(managers, area, choiceLevel);
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
	if (im->GetEscape() || im->GetX())
	{
		nextScreen = new DifficultySelectScreen(managers);
	}
	if (im->GetDown())
	{
		choice++;
		choiceLevel = 1;
		timer.start();
		if (choice == max)
			choice = 1;
	}
	if (im->GetUp())
	{
		choice--;
		choiceLevel = 1;
		timer.start();
		if (choice == 0)
			choice = max - 1;
	}
	if (im->GetRight())
	{
		if (choiceLevel!= 3)
			choiceLevel++;
		timer.start();
	}
	if (im->GetLeft())
	{
		if (choiceLevel != 1)
			choiceLevel--;
		timer.start();
	}
	if (im->GetEnter() || im->GetAttack() || im->GetA())
	{
		CheckChoice();
	}
}
