#include "GameScreen.h"


GameScreen::GameScreen(GlobalsManager::AREAS area, int level) :m_area(area), m_level(level)
{

}


GameScreen::~GameScreen()
{
	delete m_player;
}

bool GameScreen::Init()
{
	ResourceManager* r = Managers::GetResourceManager();
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
	
	m_player = new Player();

	if (!m_player->Init())
	{
		return false;
	}
	Managers::GetAIDirector()->Reset(m_level, m_area);
	timer.start();
	return true;
}

void GameScreen::Draw()
{
	m_background->Render(0, 0);
	
	Managers::GetBulletManager()->Draw();
	Managers::GetAIDirector()->Draw();
	m_player->Draw();
}

void GameScreen::Update()
{
	m_player->Update();
	
	Managers::GetAIDirector()->Update(m_player);
	Managers::GetBulletManager()->Update(m_player);

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
