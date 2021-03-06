#include "MissionBriefingScreen.h"
#include "LevelSelectScreen.h"
#include "ShopScreen.h"
#include "GameScreen.h"

MissionBriefingScreen::MissionBriefingScreen(GlobalsManager::AREAS area, int level) : m_area(area), m_level(level), choice(1)
{
}


MissionBriefingScreen::~MissionBriefingScreen()
{
	delete m_shop;
	m_shop = nullptr;
	delete m_play;
	m_play = nullptr;
}

bool MissionBriefingScreen::Init()
{
	ResourceManager* r = Managers::GetResourceManager();
	int WIDTH = Managers::GetGraphicsManager()->GetScreenWidth();
	int HEIGHT = Managers::GetGraphicsManager()->GetScreenHeight();
	if (!r->GetTexture("Background", m_background))
		return false;

	if (!r->GetTexture("menuSelector", m_selector))
		return false;

	m_shop = new Button();
	if (!m_shop->Init("ShopButton"))
		return false;
	m_play = new Button();
	if (!m_play->Init("PlayButton"))
		return false;
	m_timer.start();
	m_play->SetPosition((WIDTH/3)-m_play->GetWidth()/2, HEIGHT - m_play->GetHeight() - (50 * Managers::GetGraphicsManager()->GetScale()));
	m_shop->SetPosition((WIDTH / 3) * 2 - m_shop->GetWidth() / 2, HEIGHT - m_shop->GetHeight() - (50 * Managers::GetGraphicsManager()->GetScale()));
	m_play->SetIsSelected(true);
	return true;

}

void MissionBriefingScreen::Draw()
{
	m_background->Render( 0, 0);
	m_play->Render();
	m_shop->Render();
	if (choice == 1)
	{
		m_selector->Render( m_play->GetX() - m_selector->GetWidth() - (5 * Managers::GetGraphicsManager()->GetScale()), m_play->GetY() + ((unsigned int(m_play->GetHeight() - m_selector->GetHeight())) / 2));
	}
	else if (choice == 2)
	{
		m_selector->Render( m_shop->GetX() - m_selector->GetWidth() - (5 * Managers::GetGraphicsManager()->GetScale()), m_shop->GetY() + ((unsigned int(m_play->GetHeight() - m_selector->GetHeight())) / 2));
	}
}

void MissionBriefingScreen::Update()
{
	if (m_timer.isStarted())
	{
		if (m_timer.getTicks() < 200)
			return;
	}
	if (im->GetQuit())
	{
		mLeave = true;
	}
	if (im->GetEscape() || im->GetX())
	{
		nextScreen = new LevelSelectScreen();
	}
	if (im->GetLeft())
	{
		choice--;
		m_timer.start();
		if (choice == 0)
			choice = 2;
	}
	if (im->GetRight())
	{
		choice++;
		m_timer.start();
		if (choice == 3)
			choice = 1;
	}
	if (im->GetA() || im->GetEnter() || im->GetAttack())
	{
		if (choice == 1)
		{
			nextScreen = new GameScreen(m_area,m_level);
		}
		else
		{
			nextScreen = new ShopScreen(this);
		}
	}
	if (choice == 1)
	{
		m_play->SetIsSelected(true);
		m_shop->SetIsSelected(false);
	}
	else
	{
		m_play->SetIsSelected(false);
		m_shop->SetIsSelected(true);
	}
}
