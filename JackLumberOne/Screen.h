#pragma once
#ifndef __SCREEN_H
#define __SCREEN_H
#include <SDL.h>
#include "Managers.h"
class Screen
{
public:
	Screen(Managers* managerRef);

	~Screen();
	virtual void Update() = 0;
	virtual void Draw() = 0;

	bool GetLeave()
	{
		return mLeave;
	}
	Screen* GetNextScreen()
	{
		return nextScreen;
	}

	void MakeTTFTexture(std::string words, Texture &texture, SDL_Color colour= { 0, 0, 0 })
	{
		texture.LoadFromRenderedText(words, colour,managers->GetGraphicsManager()->GetRenderer(),managers->GetGraphicsManager()->GetFont());
	}
protected:
	Managers* managers;
	bool mLeave;
	Screen* nextScreen;
};
#endif
