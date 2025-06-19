#include "TextureManager.h"

void TextureManager::loadFromFile(const std::string& id, const std::string& path)
{
	std::thread([this, id, path]()
		{
			Texture texture;
			if (!texture.loadFromFile(path))
			{
				std::cout << "ERROR: Failed to load texture file " << id << std::endl;
				return;
			}

			std::lock_guard<std::mutex> lock(textureMtx);
			textures[id] = std::move(texture);
			std::cout << "Successfully loaded texture " << id << std::endl;

		}).detach();

	
}

Texture& TextureManager::getTexture(const std::string& id)
{
	std::lock_guard<std::mutex> lock(textureMtx);

	return textures.at(id);
}

bool TextureManager::isLoaded(const std::string& id)
{
	return textures.count(id) > 0;
}
