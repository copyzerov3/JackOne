#include "Button.h"
#include "ResourceManager.h"

Button::Button()
{
	
}
bool Button::Init(std::string name, ResourceManager* manager, bool needPressed)
{
	if(!manager->GetTexture(name + "Reg", m_regular))
		return false;
	if (needPressed)
	{
		if(!manager->GetTexture(name + "Pressed", m_pressed))
			return false;
	}
	m_selected = false;

	return true;
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
