#include "Button.h"
#include "Managers.h"
Button::Button()
{
	
}
bool Button::Init(std::string name, bool needPressed)
{
	if(!Managers::GetResourceManager()->GetTexture(name + "Reg", m_regular))
		return false;
	if (needPressed)
	{
		if (!Managers::GetResourceManager()->GetTexture(name + "Pressed", m_pressed))
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
