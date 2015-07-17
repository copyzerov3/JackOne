#pragma once
#include "Texture.h"
class Button
{
public:
	Button();
	~Button();
	bool Init(std::string name, bool needPressed = true);
	/*Draw Button at the buttons private x and y positions*/
	void Render();
	/*Draw Button at the cordinates given through parameters*/
	void Render( int x, int y);
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

