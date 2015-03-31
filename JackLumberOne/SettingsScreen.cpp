#include "SettingsScreen.h"
#include "MainMenuScreen.h"

SettingsScreen::SettingsScreen(Managers* managerRef) :Screen(managerRef)
{
}
bool SettingsScreen::Init()
{
	m_background = managers->GetResourceManager()->GetTexture("Background", m_background);
	if (m_background == nullptr)
		return false;
	m_title = new Texture();
	MakeTTFTexture("Settings", m_title);
	if (m_title == nullptr)
		return false;
	return true;
}

SettingsScreen::~SettingsScreen()
{
	delete m_title;
}

void SettingsScreen::Draw()
{
	if (m_background != nullptr)
		m_background->Render(managers->GetGraphicsManager()->GetRenderer(), 0, 0);
	if (m_title != nullptr)
		m_title->Render(managers->GetGraphicsManager()->GetRenderer(), (managers->GetGraphicsManager()->GetScreenWidth()-m_title->GetWidth())/2, 0);
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
