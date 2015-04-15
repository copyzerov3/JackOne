#include "Managers.h"

Managers::Managers()
{
	inputManager = new InputManager();
	graphicsManager = new GraphicsManager();
	resourceManager = new ResourceManager(graphicsManager);
	globalManager = new GlobalsManager();
	bulletManager = new BulletManager();
}

Managers::~Managers()
{
	delete bulletManager;
	bulletManager = nullptr;
	delete globalManager;
	globalManager = nullptr;
	delete resourceManager;
	resourceManager = nullptr;
	delete graphicsManager;
	graphicsManager = nullptr;
	delete inputManager;
	inputManager = nullptr;
}