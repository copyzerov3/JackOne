#include "GameScreen.h"


GameScreen::GameScreen(Managers* managers, GlobalsManager::AREAS area, int level) :Screen(managers), m_area(area), m_level(level)
{

}


GameScreen::~GameScreen()
{

}

bool GameScreen::Init()
{
	ResourceManager* r = managers->GetResourceManager();
	std::string file;
	switch (m_area)
	{
	case GlobalsManager::FOREST:
		file = "ForestAreaBackground";
		break;
	case GlobalsManager::DESERT:
		file = "DesertAreaBackground";
		break;
	case GlobalsManager::CITY:
		file = "CityAreaBackground";
		break;
	case GlobalsManager::SEA:
		file = "SeaAreaBackground";
		break;
	case GlobalsManager::SPACE:
		file = "SpaceAreaBackground";
		break;
	}
	if (!r->GetTexture(file, m_background))
		return false;


	timer.start();
	return true;
}

void GameScreen::Draw()
{
	int WIDTH = managers->GetGraphicsManager()->GetScreenWidth();
	int HEIGHT = managers->GetGraphicsManager()->GetScreenHeight();

	m_background->Render(r, 0, 0);
}

void GameScreen::Update()
{




	if (timer.isStarted())
	{
		if (timer.getTicks() < 200)
		{
			return;
		}
		timer.stop();
	}
	if (im->GetQuit())
	{
		mLeave = true;
	}
}
