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

void Button::Render(int x, int y)
{
	if (m_selected)
		m_pressed->Render( x, y);
	else
		m_regular->Render( x, y);
}
void Button::Render()
{
	Render( m_x, m_y);
}
