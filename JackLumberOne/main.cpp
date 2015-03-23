
#include "Game.h"
int main(int argc, char* args[])
{
	Game* game = new Game();
	if (game->Init())
	{
		do
		{
			game->Update();
		} while (!game->Leave());
	}
	delete game;
	return 0;
}