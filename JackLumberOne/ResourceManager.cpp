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
	std::string line;

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
	std::string temp;
	std::ostringstream convert;
	convert << scale;
	temp = convert.str();
	int stringHash = 0;
	while (std::getline(inFile, line))
	{
		stringHash = resources.HashFunction(line);
	//	printf("%s", line);
		line = "Assets/Images/Backgrounds/" + scalePath + line + "@" + temp + "x.png";
		image = new Texture();
		if (!image->LoadFromFile(line, graphicsRef->GetRenderer()))
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
		line = "Assets/Images/Sprites/Bosses/" + scalePath + line + "@" + temp + "x.png";
		image = new Texture();
		if (!image->LoadFromFile(line, graphicsRef->GetRenderer()))
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
	//	printf("file name : %s string Hash : %d\n", line.c_str(),stringHash);
		line = "Assets/Images/Buttons/" + scalePath + line + "@" + temp + "x.png";
		image = new Texture();
		if (!image->LoadFromFile(line, graphicsRef->GetRenderer()))
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
		line = "Assets/Images/Sprites/Enemies/" + scalePath + line + "@" + temp + "x.png";
		//printf("%s", line);
		image = new Texture();
		if (!image->LoadFromFile(line, graphicsRef->GetRenderer()))
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
		line = "Assets/Images/GUI/" + scalePath + line + "@" + temp + "x.png";
		//printf("%s", line);
		image = new Texture();
		if (!image->LoadFromFile(line, graphicsRef->GetRenderer()))
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
		line = "Assets/Images/Sprites/Player/" + scalePath + line + "@" + temp + "x.png";
		//printf("%s", line);
		image = new Texture();
		if (!image->LoadFromFile(line, graphicsRef->GetRenderer()))
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
		line = "Assets/Images/Projectiles/" + scalePath + line + "@" + temp + "x.png";
		//printf("%s", line);
		image = new Texture();
		if (!image->LoadFromFile(line, graphicsRef->GetRenderer()))
		{
			return false;
		}
		resources.Insert(stringHash, image);
	}
	if (inFile.is_open())
		inFile.close();
	return true;

}
Texture* ResourceManager::GetTexture(std::string title,Texture* container)
{
	int stringHash = resources.HashFunction(title);
	//printf("title  = %s String Hash = %d\n", title.c_str(), stringHash);
	resources.Find(stringHash, &container);
	return container;
}