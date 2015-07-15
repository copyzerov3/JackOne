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
	timer.start();
	return true;
}

void GameScreen::Draw()
{
	int WIDTH = Managers::GetGraphicsManager()->GetScreenWidth();
	int HEIGHT = Managers::GetGraphicsManager()->GetScreenHeight();

	m_background->Render(r, 0, 0);
	m_player->Draw(r);
	Managers::GetBulletManager()->Draw(r, WIDTH, HEIGHT);
}

void GameScreen::Update()
{
	m_player->Update(WIDTH,HEIGHT);
	Managers::GetBulletManager()->Update(WIDTH, HEIGHT);

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
