#include "Screen.h"


Screen::Screen(Managers* managerRef)
{
	this->managers = managerRef;
	mLeave = false;
	nextScreen = nullptr;
}


Screen::~Screen()
{
	
}
