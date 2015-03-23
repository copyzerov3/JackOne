#include "InputManager.h"
#include <stdio.h>

InputManager::InputManager()
{
	UP = DOWN = LEFT = RIGHT = SELECT = ESC = false;
	DEAD_ZONE = 8000;
	controller = NULL;
	num = -1;
}


InputManager::~InputManager()
{
	SDL_JoystickClose(controller);
	controller = NULL;
}

void InputManager::Process()
{
	//If no controller is detected check
	if (controller == NULL)
	{
		if (SDL_NumJoysticks() < 1)
		{

		}
		else
		{
			printf("Found Controller\n");
			controller = SDL_JoystickOpen(0);
			num++;
			if (controller == NULL)
			{
				printf("Warning: unable to open stream for controller, SDL Error : %s\n", SDL_GetError());
			}
		}
	}//If we had a controller make sure its still there.
	else
	{
		if (SDL_NumJoysticks() == 0)
		{
			
			printf("Lost Conttroller\n");
			controller = NULL;
		}
	}

	SDL_Event e;
	while (SDL_PollEvent(&e) != 0)
	{
		if (e.type == SDL_QUIT)
		{
			ESC = true;
		}
		else if (e.type == SDL_JOYAXISMOTION)
		{
			if (e.jaxis.which == num)
			{
				if (e.jaxis.axis == 0)
				{
					if (e.jaxis.value < -DEAD_ZONE)
					{
						LEFT = true;
					}
					else if (e.jaxis.value > DEAD_ZONE)
					{
						RIGHT = true;
					}

				}
				else if (e.jaxis.axis == 1)
				{
					if (e.jaxis.value < -DEAD_ZONE)
					{
						UP = true;
						mstickY = e.jaxis.value;
					}
					else if (e.jaxis.value > DEAD_ZONE)
					{
						DOWN = true;
						mstickY = e.jaxis.value;
					}
					else
					{
						UP = false;
						DOWN = false;
					}
				}

			}
		}
		else if (e.type == SDL_JOYBUTTONDOWN)
		{
			if (e.jbutton.which == num)
			{
				switch (e.jbutton.button)
				{
				case 10:
					ATTACK = true;
					break;
				case 4:
					SELECT = true;
					break;
				}
			}
			
		}
		else if (e.type == SDL_JOYBUTTONUP)
		{
			if (e.jbutton.which == num)
			{
				switch (e.jbutton.button)
				{
				case 10:
					ATTACK = false;
					break;
				case 4:
					SELECT = false;
					break;
				}
			}
		}
		else if (e.type == SDL_KEYDOWN)
		{
			switch (e.key.keysym.sym)
			{
			case SDLK_UP:
			case SDLK_w:
				UP = true;
				break;
			case SDLK_DOWN:
			case SDLK_s:
				DOWN = true;
				break;
			case SDLK_LEFT:
			case SDLK_a:
				LEFT = true;
				break;
			case SDLK_RIGHT:
			case SDLK_d:
				RIGHT = true;
				break;
			case SDLK_ESCAPE:
				ESC = true;
				break;
			case SDLK_RETURN:
				SELECT = true;
				break;
			}
		}
		else if (e.type == SDL_KEYUP)
		{
			switch (e.key.keysym.sym)
			{
			case SDLK_UP:
			case SDLK_w:
				UP = false;
				break;
			case SDLK_DOWN:
			case SDLK_s:
				DOWN = false;
				break;
			case SDLK_LEFT:
			case SDLK_a:
				LEFT = false;
				break;
			case SDLK_RIGHT:
			case SDLK_d:
				RIGHT = false;
				break;
			case SDLK_ESCAPE:
				ESC = false;
				break;
			case SDLK_RETURN:
				SELECT = false;
				break;
			}
		}

	}
}

