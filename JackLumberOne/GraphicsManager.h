#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include "Texture.h"
class GraphicsManager
{
public:
	GraphicsManager();
	~GraphicsManager();

	bool Init();

	void startDraw();
	void endDraw();

	void Resize(int width, int height);

	void SetFullScreen(bool fullScreen);

	TTF_Font* GetFont(){ return m_font; }
	SDL_Renderer* GetRenderer(){ return m_renderer; }

	int GetScreenHeight()
	{
		return SCREEN_HEIGHT;
	}
	int GetScreenWidth()
	{
		return SCREEN_WIDTH;
	}
	float GetScale()
	{
		return SCALE;
	}

private:
	void Remake();
	void SetScale();
	SDL_Window* m_window;
	SDL_Renderer* m_renderer;
	TTF_Font* m_font;

	Texture m_screenTexture;
	//Screen dimension constants
	int SCREEN_WIDTH;
	int SCREEN_HEIGHT;
	float SCALE;
	bool m_fullScreen;
};

