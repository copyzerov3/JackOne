#include "Screen.h"


Screen::Screen()
{

	mLeave = false;
	nextScreen = nullptr;
	HEIGHT = Managers::GetGraphicsManager()->GetScreenHeight();
	WIDTH = Managers::GetGraphicsManager()->GetScreenWidth();
	r = Managers::GetGraphicsManager()->GetRenderer();
	im = Managers::GetInputManager();
	scaleMode = Managers::GetGraphicsManager()->GetScale();
}


Screen::~Screen()
{
	
}
