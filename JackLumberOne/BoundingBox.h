#pragma once
class BoundingBox
{
public:
	BoundingBox(int x = 0,int y = 0,int width = 0, int height = 0);
	~BoundingBox();
	static bool Collided(BoundingBox box1, BoundingBox box2)
	{
		if ((box1.GetX() + box1.GetWidth()) >= box2.GetX() && box1.GetX() <= (box2.GetX() + box2.GetWidth()))
		{
			if ((box1.GetY() + box1.GetHeight()) >= box2.GetY() && box1.GetY() <= (box2.GetY() + box2.GetHeight()))
			{
				return true;
			}
		}
		return false;
	}
	static bool Collided(int x1, int y1, int width1, int height1, int x2, int y2, int width2, int height2)
	{
		return Collided(BoundingBox(x1, y1, width1, height1), BoundingBox(x2, y2, width2, height2));
	}
	void Init(int x, int y, int width, int height)
	{
		SetPosition(x, y);
		SetWidth(width);
		SetHeight(height);
	}
	int GetX(){ return m_x; }
	int GetY(){ return m_y; }
	int GetWidth(){ return m_width; }
	int GetHeight(){ return m_height; }
	void SetWidth(int width)
	{
		m_width = width;
	}
	void SetHeight(int height)
	{
		m_height = height;
	}
	void SetPosition(int x, int y)
	{
		m_x = x;
		m_y = y;
	}
private:
	int m_x, m_y, m_width, m_height;
};

