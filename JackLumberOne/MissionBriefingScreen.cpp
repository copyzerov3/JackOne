#include "MissionBriefingScreen.h"
#include "LevelSelectScreen.h"

MissionBriefingScreen::MissionBriefingScreen(Managers* managersRef, GlobalsManager::AREAS area, int level) :Screen(managersRef), m_area(area), m_level(level), choice(1)
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
	ResourceManager* r = managers->GetResourceManager();
	int WIDTH = managers->GetGraphicsManager()->GetScreenWidth();
	int HEIGHT = managers->GetGraphicsManager()->GetScreenHeight();
	if (!r->GetTexture("Background", m_background))
		return false;
	m_shop = new Button();
	if (!m_shop->Init("ShopButton", r))
		return false;
	m_play = new Button();
	if (!m_play->Init("PlayButton", r))
		return false;
	m_timer.start();
	m_play->SetPosition((WIDTH/3)-m_play->GetWidth()/2, HEIGHT - m_play->GetHeight() - (50 * scaleMode));
	m_shop->SetPosition((WIDTH/3)*2 - m_shop->GetWidth()/2, HEIGHT - m_shop->GetHeight() - (50 * scaleMode));
	return true;
}

void MissionBriefingScreen::Draw()
{
	m_background->Render(r, 0, 0);
	m_play->Render(r);
	m_shop->Render(r);
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
		nextScreen = new LevelSelectScreen(managers);
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
}
