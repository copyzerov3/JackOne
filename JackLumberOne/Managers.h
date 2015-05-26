#pragma once
#ifndef MANAGERS_H
#define MANAGERS_H

#include "InputManager.h"
#include "GraphicsManager.h"
#include "ResourceManager.h"
#include "GlobalsManager.h"
#include "BulletManager.h"
class BulletManager;

class Managers
{
public:
	Managers();
	~Managers();
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
	BulletManager* GetBulletManager()
	{
		return bulletManager;
	}
private:
	InputManager* inputManager;
	GraphicsManager* graphicsManager;
	ResourceManager* resourceManager;
	GlobalsManager* globalManager;
	BulletManager* bulletManager;
};

#endif