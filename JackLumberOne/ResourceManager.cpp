#include "ResourceManager.h"

ResourceManager::ResourceManager(GraphicsManager* graphicsRef) :resources(100)
{
	this->graphicsRef = graphicsRef;
}


ResourceManager::~ResourceManager()
{

}
bool ResourceManager::Init()
{
	Texture image;
	
	if (!image.LoadFromFile("Assets/images/background.png", graphicsRef->GetRenderer()))
		return false;

	int stringHash = resources.HashFunction(std::string("background"));
	resources.Insert(stringHash, image);
	
	Texture imageTwo;
	if (!imageTwo.LoadFromFile("Assets/images/menuSelector.png", graphicsRef->GetRenderer()))
		return false;
	stringHash = resources.HashFunction(std::string("selector"));
	resources.Insert(stringHash, imageTwo);

	return true;
}
bool ResourceManager::GetTexture(std::string title,Texture* container)
{
	int stringHash = resources.HashFunction(title);
	return resources.Find(stringHash, container);
}