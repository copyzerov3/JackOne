#include "SettingsScreen.h"


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
	if (managers->GetInputManager()->GetEscape())
	{
		mLeave = true;
	}
}
