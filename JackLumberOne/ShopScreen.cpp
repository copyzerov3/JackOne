#include "ShopScreen.h"

ShopScreen::ShopScreen( MissionBriefingScreen* prevScreen) : m_prevScreen(prevScreen)
{

}


ShopScreen::~ShopScreen()
{
	delete m_title;
	m_title = nullptr;
}

bool ShopScreen::Init()
{
	ResourceManager* r = Managers::GetResourceManager();
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
	m_background->Render( 0, 0);
	m_title->Render( (Managers::GetGraphicsManager()->GetScreenWidth() - m_title->GetWidth())/2, 0);
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
