#include "Managers.h"
InputManager* Managers::m_inputManager = nullptr;
GraphicsManager* Managers::m_graphicsManager = nullptr;
ResourceManager* Managers::m_resourceManager = nullptr;
GlobalsManager* Managers::m_globalManager = nullptr;
BulletManager* Managers::m_bulletManager = nullptr;
AIDirector* Managers::m_aiDirector = nullptr;
Managers* Managers::m_managers = nullptr;
Managers::Managers()
{
	m_inputManager = new InputManager();
	m_graphicsManager = new GraphicsManager();
	m_resourceManager = new ResourceManager(m_graphicsManager);
	m_globalManager = new GlobalsManager();
	m_bulletManager = new BulletManager();
	m_aiDirector = new AIDirector();
}

Managers::~Managers()
{
	delete m_aiDirector;
	m_aiDirector = nullptr;
	delete m_bulletManager;
	m_bulletManager = nullptr;
	delete m_globalManager;
	m_globalManager = nullptr;
	delete m_resourceManager;
	m_resourceManager = nullptr;
	delete m_graphicsManager;
	m_graphicsManager = nullptr;
	delete m_inputManager;
	m_inputManager = nullptr;
}