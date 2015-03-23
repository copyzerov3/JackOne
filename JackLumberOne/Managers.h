#pragma once
#include "InputManager.h"
#include "GraphicsManager.h"
#include "ResourceManager.h"
class Managers
{
public:
	Managers()
	{
		inputManager = new InputManager();
		graphicsManager = new GraphicsManager();
		resourceManager = new ResourceManager(graphicsManager);
	}
	~Managers()
	{
		delete resourceManager;
		resourceManager = NULL;
		delete graphicsManager;
		graphicsManager = NULL;
		delete inputManager;
		inputManager = NULL;

	}
	bool Init()
	{
		if (!graphicsManager->Init())
		{
			return false;
		}
		if (!resourceManager->Init())
		{
			return false;
		}
		return true;
	}
	InputManager* GetInputManager()
	{
		return inputManager;
	}
	GraphicsManager* GetGraphicsManager()
	{
		return graphicsManager;
	}
	ResourceManager* GetResourceManager()
	{
		return resourceManager;
	}
private:
	InputManager* inputManager;
	GraphicsManager* graphicsManager;
	ResourceManager* resourceManager;
};

