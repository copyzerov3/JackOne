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
		if (!m_graphicsManager->Init())
		{
			return false;
		}
		if (!m_resourceManager->Init())
		{
			return false;
		}
		return true;
	}
	static InputManager* GetInputManager()
	{
		return m_inputManager;
	}
	static GraphicsManager* GetGraphicsManager()
	{
		return m_graphicsManager;
	}
	static ResourceManager* GetResourceManager()
	{
		return m_resourceManager;
	}
	static GlobalsManager* GetGlobalsManager()
	{
		return m_globalManager;
	}
	static BulletManager* GetBulletManager()
	{
		return m_bulletManager;
	}
	static Managers* GetManagers()
	{
		if (m_managers == nullptr)
		{
			m_managers = new Managers();
		}
		return m_managers;
	}
private:
	static InputManager* m_inputManager;
	static GraphicsManager* m_graphicsManager;
	static ResourceManager* m_resourceManager;
	static GlobalsManager* m_globalManager;
	static BulletManager* m_bulletManager;
	
	static Managers* m_managers;
};

#endif