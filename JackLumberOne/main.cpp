
#include "Game.h"
int main(int argc, char* args[])
{
	Game* game = new Game();
	if (game->Init())
	{
		do
		{
			if (!game->Update())
			{
				delete game;
				return 1;
			}
				
		} while (!game->Leave());
	}
	delete game;
	return 0;
}