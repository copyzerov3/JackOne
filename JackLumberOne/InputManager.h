#pragma once
#include <SDL.h>
class InputManager
{
public:
	InputManager();
	~InputManager();
	void Process();
	bool GetUp(){ return UP; }
	bool GetDown(){ return DOWN; }
	bool GetLeft(){ return LEFT; }
	bool GetRight(){ return RIGHT; }
	bool GetSelect(){ return SELECT; }
	bool GetEscape(){ return ESC; }
	bool GetAttack(){ return ATTACK; }
	bool GetQuit(){ return QUIT; }
private:
	bool UP, DOWN, LEFT, RIGHT, SELECT,ESC,ATTACK,QUIT;
	int mstickX, mstickY;
	int DEAD_ZONE;
	SDL_Joystick* controller;
	int num;
};

