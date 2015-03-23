#include "SettingsScreen.h"
#include "MainMenuScreen.h"

SettingsScreen::SettingsScreen(Managers* managerRef) :Screen(managerRef)
{
	managerRef->GetResourceManager()->GetTexture("background", &m_background);
	MakeTTFTexture("Settings", m_title);
}


SettingsScreen::~SettingsScreen()
{
	m_title.Free();
}

void SettingsScreen::Draw()
{

	m_background.Render(managers->GetGraphicsManager()->GetRenderer(), 0, 0);
	m_title.Render(managers->GetGraphicsManager()->GetRenderer(), (managers->GetGraphicsManager()->GetScreenWidth()-m_title.GetWidth())/2, 0);
}

void SettingsScreen::Update()
{
	if (managers->GetInputManager()->GetQuit())
	{
		mLeave = true;
	}
	else if (managers->GetInputManager()->GetEscape())
	{
		nextScreen = new MainMenuScreen(managers);
	}
}
