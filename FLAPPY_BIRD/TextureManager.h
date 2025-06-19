#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include "Definitions.h"

#include <SFML/Graphics.hpp>
#include <string>
#include <map>
#include <thread>
#include <mutex>
#include <iostream>

using namespace sf;

class TextureManager
{
private:
	std::map<std::string, Texture> textures;
	std::mutex textureMtx;

public:
	void loadFromFile(const std::string& id, const std::string& path);
	Texture& getTexture(const std::string& id);

	bool isLoaded(const std::string& id);
};


#endif 



