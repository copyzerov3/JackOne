#include "Button.h"
#include "ResourceManager.h"

Button::Button(std::string name,ResourceManager* manager,bool needPressed)
{
	manager->GetTexture(name + "Reg", &m_regular);
	if (needPressed)
	{
		manager->GetTexture(name + "Pressed", &m_pressed);
	}
	m_selected = false;
}


Button::~Button()
{
}

void Button::Render(int x, int y, SDL_Renderer* renderer)
{

}
