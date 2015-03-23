#include "GraphicsManager.h"


GraphicsManager::GraphicsManager()
{
	SCREEN_WIDTH = 800;
	SCREEN_HEIGHT = 600;
	m_fullScreen = false;
}


GraphicsManager::~GraphicsManager()
{
	TTF_CloseFont(m_font);
	m_font = NULL;
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);
	m_window = NULL;
	m_renderer = NULL;
}
void GraphicsManager::endDraw()
{
	/*SDL_SetRenderTarget(m_renderer, NULL);
	//Show rendered to texture
	SDL_Rect rect = { 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT };
	m_screenTexture.RenderAsBuffer(m_renderer, &rect);*/
	if (m_renderer != NULL)
		SDL_RenderPresent(m_renderer);
}
void GraphicsManager::startDraw()
{
	//m_screenTexture.SetAsRenderTarget(m_renderer);
	if (m_renderer != NULL)
		SDL_RenderClear(m_renderer);
}
void GraphicsManager::Resize(int width,int height)
{
	SCREEN_WIDTH = width;
	SCREEN_HEIGHT = height;
	Remake();
}
void GraphicsManager::SetFullScreen(bool fullScreen)
{
	m_fullScreen = fullScreen;
	Remake();

}
void GraphicsManager::Remake()
{
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);
	m_window = NULL;
	m_renderer = NULL;

	Init();
}
bool GraphicsManager::Init()
{
	m_window = NULL;
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK) < 0)
	{
		printf("SDL COULD NOT INIT VIDEO, SDL ERROR : %s\n", SDL_GetError());
		return false;
	}
	else
	{
		if (!m_fullScreen)
			m_window = SDL_CreateWindow("Jack Lumber", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		else
			m_window = SDL_CreateWindow("Jack Lumber", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN|SDL_WINDOW_FULLSCREEN);

		if (m_window == NULL)
		{
			printf("Window could not be made, SDL ERROR : %s\n", SDL_GetError());
			return false;
		}
		else
		{
			m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if (m_renderer == NULL)
			{
				printf("Renderer could not be created! SDL Error : %s\n", SDL_GetError());
			}
			else
			{
				SDL_SetRenderDrawColor(m_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
				m_screenTexture.CreateBlank(m_renderer, 1920, 1080, SDL_TEXTUREACCESS_TARGET);
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_Image could not init, SDL Error %s\n", IMG_GetError());
					return false;
				}
				if (TTF_Init() == -1)
				{
					printf("Could not init font render to texture");
					return false;
				}
				else
				{
					m_font = TTF_OpenFont("Assets/Data/regular.ttf", 28);
					if (!m_font)
					{
						printf("Could not open TTF %s\n", TTF_GetError());
						return false;
					}
				}
				
			}
		}
	}

	return true;
}