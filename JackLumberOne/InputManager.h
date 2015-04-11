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
	bool GetEscape(){ return ESC; }
	bool GetAttack(){ return ATTACK; }
	bool GetQuit(){ return QUIT; }
	bool GetEnter(){ return ENTER; }
	bool GetSelect(){ return SELECT; }
	bool GetA(){ return A; }
	bool GetB(){ return B; }
	bool GetX(){ return X; }
	bool GetY(){ return Y; }
	bool GetL(){ return L; }
	bool GetR(){ return R; }
	bool GetD_Down(){ return D_DOWN; }
	bool GetD_Up(){ return D_UP; }
	bool GetD_Left(){ return D_LEFT; }
	bool GetD_Right(){ return D_RIGHT; }
	bool GetRThree(){ return RTHREE; }
	bool GetLThree(){ return LTHREE; }

private:
	bool UP,
		DOWN,
		LEFT,
		RIGHT,
		ESC,
		ATTACK,
		QUIT,
		ENTER,
		START,
		SELECT,
		A,
		B,
		X,
		Y,
		L,
		R,
		D_DOWN,
		D_UP,
		D_LEFT,
		D_RIGHT,
		RTHREE,
		LTHREE;
	int mstickX, mstickY;
	int DEAD_ZONE;
	SDL_Joystick* controller;
	int num;
};

