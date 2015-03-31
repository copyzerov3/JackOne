#pragma once
#include "Texture.h"
#include "ResourceManager.h"
class Button
{
public:
	Button();
	~Button();
	bool Init(std::string name, ResourceManager* manager, bool needPressed = true);
	void Render(SDL_Renderer* renderer);
	void Render(SDL_Renderer*, int x, int y);
	int GetWidth()
	{
		return m_regular->GetWidth();
	}
	int GetHeight()
	{
		return m_regular->GetHeight();
	}
	void SetIsSelected(bool isSelected)
	{
		m_selected = isSelected;
	}
	bool IsSelected()
	{
		return m_selected;
	}
	int GetX()
	{
		return m_x;
	}
	int GetY()
	{
		return m_y;
	}
	void SetX(int x)
	{
		m_x = x;
	}
	void SetY(int y)
	{
		m_y = y;
	}
	void SetPosition(int x, int y)
	{
		SetX(x);
		SetY(y);
	}
private:
	bool m_selected;
	Texture* m_regular,*m_pressed;
	int m_x, m_y;

};

