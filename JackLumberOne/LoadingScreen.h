#pragma once
#include "Screen.h"

class LoadingScreen :
	public Screen
{
public:
	LoadingScreen(Managers* managerRef);
	~LoadingScreen();
	void Update();
	void Draw();
	bool Init();
private:
	
};

