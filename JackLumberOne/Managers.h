#pragma once
#include "InputManager.h"
#include "GraphicsManager.h"
#include "ResourceManager.h"
#include "GlobalsManager.h"
class Managers
{
public:
	Managers()
	{
		inputManager = new InputManager();
		graphicsManager = new GraphicsManager();
		resourceManager = new ResourceManager(graphicsManager);
		globalManager = new GlobalsManager();
	}
	~Managers()
	{
		delete globalManager;
		globalManager = nullptr;
		delete resourceManager;
		resourceManager = nullptr;
		delete graphicsManager;
		graphicsManager = nullptr;
		delete inputManager;
		inputManager = nullptr;

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
	GlobalsManager* GetGlobalsManager()
	{
		return globalManager;
	}
private:
	InputManager* inputManager;
	GraphicsManager* graphicsManager;
	ResourceManager* resourceManager;
	GlobalsManager* globalManager;
};

