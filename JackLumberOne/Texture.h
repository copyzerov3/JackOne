#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#pragma once
class Texture
{
public:
	Texture();
	~Texture();

	bool LoadFromFile(std::string path,SDL_Renderer* renderer);

	bool LoadFromRenderedText(std::string textureText, SDL_Color textColor,SDL_Renderer* renderer,TTF_Font* font);

	bool CreateBlank(SDL_Renderer* renderer,int width, int height, SDL_TextureAccess = SDL_TEXTUREACCESS_STREAMING);

	void Free();

	void SetColor(Uint8 red, Uint8 green, Uint8 blue);

	void SetBlendMode(SDL_BlendMode blending);

	void SetAlpha(Uint8 alpha);

	void Render(SDL_Renderer* renderer,int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);

	void SetAsRenderTarget(SDL_Renderer* renderer)
	{
		SDL_SetRenderTarget(renderer, m_texture);
	}
	void RenderAsBuffer(SDL_Renderer* renderer, SDL_Rect* screen);
	int GetWidth();
	int GetHeight();
private:
	SDL_Texture* m_texture;

	int m_width;
	int m_height;
	int m_deleteAttempts;
};

