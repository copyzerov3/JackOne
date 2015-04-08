#include "Texture.h"


Texture::Texture()
{
	m_texture = NULL;
	m_width = 0;
	m_height = 0;
}


Texture::~Texture()
{
	Free();
}

bool Texture::CreateBlank(SDL_Renderer* renderer,int width, int height, SDL_TextureAccess access)
{
	m_texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, access, width, height);

	if (m_texture == NULL)
	{
		printf("Could not create blank texture SDL Error : %s\n", SDL_GetError());
		return false;
	}
	else
	{
		m_width = width;
		m_height = height;
	}
	return true;
}
bool Texture::LoadFromFile(std::string path,SDL_Renderer* renderer,std::string name)
{
	Free();
	m_name = name;
	SDL_Texture* newTexture = NULL;

	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image error %\n", path.c_str(), IMG_GetError());
	}
	else
	{
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));

		newTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error : %s\n", path.c_str(), SDL_GetError());
		}
		else
		{
			m_width = loadedSurface->w;
			m_height = loadedSurface->h;
		}

		SDL_FreeSurface(loadedSurface);
	}

	m_texture = newTexture;
	return m_texture != NULL;
}

bool Texture::LoadFromRenderedText(std::string textureText, SDL_Color textColor,SDL_Renderer* renderer,TTF_Font* font)
{
	Free();

	SDL_Surface* textSurface = TTF_RenderText_Solid(font, textureText.c_str(), textColor);
	if (textSurface == NULL)
	{
		printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
	}
	else
	{
		m_texture = SDL_CreateTextureFromSurface(renderer, textSurface);
		if (m_texture == NULL)
		{
			printf("Unable to create texture from rendered text! SDL Error %s\n", SDL_GetError());
		}
		else
		{
			m_width = textSurface->w;
			m_height = textSurface->h;
		}
		SDL_FreeSurface(textSurface);
	}
	return m_texture != NULL;
}

void Texture::Free()
{
	if (m_texture != NULL)
	{
		SDL_DestroyTexture(m_texture);
		m_texture = NULL;
		m_width = 0;
		m_height = 0;
	}
}

void Texture::SetColor(Uint8 red, Uint8 green, Uint8 blue)
{
	SDL_SetTextureColorMod(m_texture, red, green, blue);
}

void Texture::SetBlendMode(SDL_BlendMode blending)
{
	SDL_SetTextureBlendMode(m_texture, blending);
}

void Texture::SetAlpha(Uint8 alpha)
{
	SDL_SetTextureAlphaMod(m_texture, alpha);
}
void Texture::Render(SDL_Renderer* renderer,int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip)
{

	SDL_Rect renderQuad = { x, y, m_width, m_height };

	if (clip != NULL)
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	SDL_RenderCopyEx(renderer, m_texture, clip, &renderQuad, angle, center, flip);

}
void Texture::RenderAsBuffer(SDL_Renderer* renderer,SDL_Rect* screen)
{
	SDL_RenderCopyEx(renderer, m_texture, NULL, screen, 0.0, NULL, SDL_FLIP_NONE);
}
int Texture::GetWidth()
{
	return m_width;
}
int Texture::GetHeight()
{
	return m_height;
}
