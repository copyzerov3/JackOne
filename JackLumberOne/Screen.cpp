#include "Screen.h"


Screen::Screen()
{

	mLeave = false;
	nextScreen = nullptr;
	r = Managers::GetGraphicsManager()->GetRenderer();
	im = Managers::GetInputManager();
}


Screen::~Screen()
{
	
}
