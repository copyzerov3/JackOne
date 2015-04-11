#include "InputManager.h"
#include <stdio.h>

InputManager::InputManager()
{
	UP = DOWN = LEFT = RIGHT = SELECT = ESC = QUIT = false;
	DEAD_ZONE = 10000;
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
			QUIT = true;
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
					else
					{
						LEFT = false;
						RIGHT = false;
					}

				}
				else if (e.jaxis.axis == 1)
				{
					if (e.jaxis.value < -DEAD_ZONE)
					{
						UP = true;
					}
					else if (e.jaxis.value > DEAD_ZONE)
					{
						DOWN = true;
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
				case 0:
					D_UP = true;
					break;
				case 1:
					D_DOWN = true;
					break;
				case 2:
					D_LEFT = true;
					break;
				case 3:
					D_RIGHT = true;
					break;
				case 4:
					START = true;
					break;
				case 5:
					SELECT = true;
					break;
				case 6:
					LTHREE = true;
					break;
				case 7:
					RTHREE = true;
					break;
				case 8:
					L = true;
					break;
				case 9:
					R = true;
					break;
				case 10:
					A = true;
					break;
				case 11:
					B = true;
					break;
				case 12:
					X = true;
					break;
				case 13:
					Y = true;
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
				case 0:
					D_UP = false;
					break;
				case 1:
					D_DOWN = false;
					break;
				case 2:
					D_LEFT =false;
					break;
				case 3:
					D_RIGHT = false;
					break;
				case 4:
					START = false;
					break;
				case 5:
					SELECT = false;
					break;
				case 6:
					LTHREE = false;
					break;
				case 7:
					RTHREE = false;
					break;
				case 8:
					L = false;
					break;
				case 9:
					R = false;
					break;
				case 10:
					A = false;
					break;
				case 11:
					B = false;
					break;
				case 12:
					X = false;
					break;
				case 13:
					Y = false;
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
				ENTER = true;
				break;
			case SDLK_SPACE:
				ATTACK = true;
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
				ENTER = false;
				break;
			case SDLK_SPACE:
				ATTACK = false;
				break;
			}
		}

	}
}

