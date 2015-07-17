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

	bool LoadFromFile(std::string path,std::string name);

	bool LoadFromRenderedText(std::string textureText, SDL_Color textColor,TTF_Font* font);

	bool CreateBlank(int width, int height, SDL_TextureAccess = SDL_TEXTUREACCESS_STREAMING);

	void Free();

	void SetColor(Uint8 red, Uint8 green, Uint8 blue);

	void SetBlendMode(SDL_BlendMode blending);

	void SetAlpha(Uint8 alpha);

	void Render(int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);

	void SetAsRenderTarget();
	void RenderAsBuffer( SDL_Rect* screen);
	int GetWidth();
	int GetHeight();
	std::string GetName()
	{
		return m_name;
	}
private:
	SDL_Texture* m_texture;
	std::string m_name;
	int m_width;
	int m_height;
};

