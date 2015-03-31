#include "Button.h"
#include "ResourceManager.h"

Button::Button(std::string name,ResourceManager* manager,bool needPressed)
{
	m_regular = manager->GetTexture(name + "Reg", m_regular);
	if (needPressed)
	{
		m_pressed = manager->GetTexture(name + "Pressed", m_pressed);
	}
	m_selected = false;
}


Button::~Button()
{
	
}

void Button::Render( SDL_Renderer* renderer,int x, int y)
{
	if (m_selected)
		m_pressed->Render(renderer, x, y);
	else
		m_regular->Render(renderer, x, y);
}
void Button::Render(SDL_Renderer* renderer)
{
	Render(renderer, m_x, m_y);
}
