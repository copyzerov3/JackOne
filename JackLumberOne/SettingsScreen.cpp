#include "SettingsScreen.h"
#include "MainMenuScreen.h"

SettingsScreen::SettingsScreen(Managers* managerRef) :Screen(managerRef)
{
}
bool SettingsScreen::Init()
{
	if(!managers->GetResourceManager()->GetTexture("Background", m_background))
		return false;
	MakeTTFTexture("Settings", m_title);
	return true;
}

SettingsScreen::~SettingsScreen()
{
	delete m_title;
}

void SettingsScreen::Draw()
{
	if (m_background != nullptr)
		m_background->Render(r, 0, 0);
	if (m_title != nullptr)
		m_title->Render(r, (managers->GetGraphicsManager()->GetScreenWidth()-m_title->GetWidth())/2, 0);
}

void SettingsScreen::Update()
{
	if (im->GetQuit())
	{
		mLeave = true;
	}
	else if (im->GetEscape() || im->GetX())
	{
		nextScreen = new MainMenuScreen(managers);
	}
}
