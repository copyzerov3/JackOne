#pragma once
#include "Texture.h"
class Button
{
public:
	Button(std::string name, ResourceManager* manager, bool needPressed = true);
	~Button();
	void Render(int x,int y,SDL_Renderer* renderer);
	int GetWidth()
	{
		return m_regular.GetWidth();
	}
	int GetHeight()
	{
		return m_regular.GetHeight();
	}
	void SetIsSelected(bool isSelected)
	{
		m_selected = isSelected;
	}
	bool IsSelected()
	{
		return m_selected;
	}
private:
	bool m_selected;
	Texture m_regular,m_pressed;

};

