#include "ResourceManager.h"
#include <fstream>
#include <string>
#include <sstream>
ResourceManager::ResourceManager(GraphicsManager* graphicsRef) :resources(300)
{
	this->graphicsRef = graphicsRef;
}


ResourceManager::~ResourceManager()
{

}
bool ResourceManager::Init()
{
	Texture* image;
	std::ifstream inFile("Assets/Images/Backgrounds.txt");
	std::string line = "";
	std::string name = "";
	float scale = graphicsRef->GetScale();
	std::string scalePath;

	if (scale == 1.0f)
	{
		scalePath = "";
	}
	else
	{
		scalePath = "2x/";
	}
	int stringHash = 0;
	while (std::getline(inFile, line))
	{
		stringHash = resources.HashFunction(line);
	//	printf("%s", line);
		name = line;
		line = "Assets/Images/Backgrounds/" + scalePath + line + ".png";
		image = new Texture();
		if (!image->LoadFromFile(line,name))
		{
			return false;
		}
		resources.Insert(stringHash, image);
	}
	if (inFile.is_open())
		inFile.close();
	inFile.open("Assets/Images/Bosses.txt");
	while (std::getline(inFile, line))
	{
		stringHash = resources.HashFunction(line);
		//printf("%s\n", line);
		name = line;
		line = "Assets/Images/Sprites/Bosses/" + scalePath + line + ".png";
		image = new Texture();
		if (!image->LoadFromFile(line, name))
		{
			return false;
		}
		resources.Insert(stringHash, image);
	}
	if (inFile.is_open())
		inFile.close();



	inFile.open("Assets/Images/Buttons.txt");
	while (std::getline(inFile, line))
	{
		stringHash = resources.HashFunction(line);
		//printf("file name : %s string Hash : %d\n", line.c_str(),stringHash);
		name = line;
		line = "Assets/Images/Buttons/" + scalePath + line +".png";
		image = new Texture();
		if (!image->LoadFromFile(line, name))
		{
			return false;
		}
		resources.Insert(stringHash, image);
	}
	if (inFile.is_open())
		inFile.close();


	inFile.open("Assets/Images/Enemies.txt");
	while (std::getline(inFile, line))
	{
		stringHash = resources.HashFunction(line);
		name = line;
		line = "Assets/Images/Sprites/Enemies/" + scalePath + line + ".png";
		//printf("%s", line);
		image = new Texture();
		if (!image->LoadFromFile(line, name))
		{
			return false;
		}
		resources.Insert(stringHash, image);
	}
	if (inFile.is_open())
		inFile.close();
	inFile.open("Assets/Images/GUI.txt");
	while (std::getline(inFile, line))
	{
		stringHash = resources.HashFunction(line);
		name = line;
		line = "Assets/Images/GUI/" + scalePath + line +".png";
		//printf("%s", line);
		image = new Texture();
		if (!image->LoadFromFile(line, name))
		{
			return false;
		}
		resources.Insert(stringHash, image);
	}
	if (inFile.is_open())
		inFile.close();
	inFile.open("Assets/Images/Player.txt");
	while (std::getline(inFile, line))
	{
		stringHash = resources.HashFunction(line);
		name = line;
		line = "Assets/Images/Sprites/Player/" + scalePath + line + ".png";
		//printf("%s", line);
		image = new Texture();
		if (!image->LoadFromFile(line, name))
		{
			return false;
		}
		resources.Insert(stringHash, image);
	}
	if (inFile.is_open())
		inFile.close();
	inFile.open("Assets/Images/Projectiles.txt");
	while (std::getline(inFile, line))
	{
		stringHash = resources.HashFunction(line);
		name = line;
		line = "Assets/Images/Projectiles/" + scalePath + line + ".png";
		//printf("%s", line);
		image = new Texture();
		if (!image->LoadFromFile(line, name))
		{
			return false;
		}
		resources.Insert(stringHash, image);
	}
	if (inFile.is_open())
		inFile.close();
	return true;

}
bool ResourceManager::GetTexture(std::string title,Texture* &container)
{
	int stringHash = resources.HashFunction(title);
	int org = stringHash;
	if (!resources.Find(stringHash, &container))
	{
		printf("Did not find image with name %s", title.c_str());
		return false;
	}
	if (container->GetName() != title)
	{
		stringHash++;
		while (stringHash%resources.GetSize() != org)
		{
			
			if (!resources.FindWithHash(stringHash%resources.GetSize(),&container,org))
			{
				printf("Did not find image with name %s", title.c_str());
				return false;
			}
			else
			{
				if (container->GetName() != title)
				{
					stringHash++;
				}
				return true;
			}
			
		}
	}
	return true;
}