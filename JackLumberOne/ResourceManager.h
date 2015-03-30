#pragma once
#include "Texture.h"
#include "HashTable.h"
#include "GraphicsManager.h"

class ResourceManager
{
public:
	ResourceManager(GraphicsManager* graphicsRef);
	~ResourceManager();
	Texture* GetTexture(std::string name,Texture* texture);
	bool Init();
private:
	HashTable<Texture*> resources;
	GraphicsManager* graphicsRef;
};

