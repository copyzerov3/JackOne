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

	m_enemy = new ShieldEnemy();
	if (!m_enemy->Init(Managers::GetGraphicsManager()->GetScreenWidth() + 400, 300))
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

	m_background->Render(0, 0);
	m_player->Draw();
	m_enemy->Draw();
	Managers::GetBulletManager()->Draw();
}

void GameScreen::Update()
{
	m_player->Update();
	m_enemy->Update(m_player);
	Managers::GetBulletManager()->Update();

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
	if (im->GetEnter())
	{
		m_enemy->TakeDamage(0, false);
		timer.start();
	}
}
