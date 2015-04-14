#include "ShopScreen.h"

ShopScreen::ShopScreen(Managers* managers, MissionBriefingScreen* prevScreen) :Screen(managers), m_prevScreen(prevScreen)
{

}


ShopScreen::~ShopScreen()
{
	delete m_title;
	m_title = nullptr;
}

bool ShopScreen::Init()
{
	ResourceManager* r = managers->GetResourceManager();
	if (!r->GetTexture("Background", m_background))
		return false;
	MakeTTFTexture("Shop Screen", m_title);
	if (m_title == nullptr)
		return false;

	timer.start();
	return true;
}

void ShopScreen::Draw()
{
	m_background->Render(r, 0, 0);
	m_title->Render(r, (WIDTH - m_title->GetWidth())/2, 0);
}

void ShopScreen::Update()
{
	if (timer.isStarted())
	{
		if (timer.getTicks() < 200)
			return;
		timer.stop();
	}
	if (im->GetEscape())
	{
		nextScreen = m_prevScreen;
	}
	if (im->GetQuit())
	{
		mLeave = true;
	}

}
