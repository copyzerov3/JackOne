#include "Screen.h"


Screen::Screen(Managers* managerRef)
{
	this->managers = managerRef;
	mLeave = false;
	nextScreen = nullptr;
	HEIGHT = managers->GetGraphicsManager()->GetScreenHeight();
	WIDTH = managers->GetGraphicsManager()->GetScreenWidth();
	r = managers->GetGraphicsManager()->GetRenderer();
	im = managers->GetInputManager();
	scaleMode = managers->GetGraphicsManager()->GetScale();
}


Screen::~Screen()
{
	
}
