#include "SettingsScreen.h"
#include "MainMenuScreen.h"

SettingsScreen::SettingsScreen(Managers* managerRef) :Screen(managerRef)
{
	managerRef->GetResourceManager()->GetTexture("background", &m_background);

}


SettingsScreen::~SettingsScreen()
{
}

void SettingsScreen::Draw()
{
	m_background.Render(managers->GetGraphicsManager()->GetRenderer(), 100, 0);
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
