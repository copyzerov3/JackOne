#pragma once
#ifndef __SCREEN_H
#define __SCREEN_H
#include <SDL.h>
#include "Texture.h"
#include "Managers.h"

class Screen
{
public:
	Screen();

	~Screen();
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual bool Init() = 0;

	bool GetLeave()
	{
		return mLeave;
	}
	Screen* GetNextScreen()
	{
		return nextScreen;
	}

	void MakeTTFTexture(std::string words, Texture* &texture, SDL_Color colour= { 0, 0, 0 })
	{
		if (texture == nullptr)
			texture = new Texture();
		texture->LoadFromRenderedText(words, colour, Managers::GetGraphicsManager()->GetRenderer(), Managers::GetGraphicsManager()->GetFont());
	}
protected:
	bool mLeave;
	Screen* nextScreen;
	SDL_Renderer* r;
	InputManager* im;
	int WIDTH;
	int HEIGHT;
	int scaleMode;
};
#endif
