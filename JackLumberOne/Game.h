#pragma once
#include <stdio.h>
#include "Timer.h"
#include "Managers.h"
#include "Screen.h"
class Game
{
public:
	Game();
	~Game();
	bool Init();
	bool Leave();
	bool Update();

private:
	Screen* m_screen;

	const int SCREEN_FPS = 60;
	const int SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS;

	Timer fpsTimer;
	Timer capTimer;

	int countedFrames = 0;

};

