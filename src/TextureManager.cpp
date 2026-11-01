#include "TextureManager.h"
#include "PathValidator.h"

void TextureManager::loadFromFile(const std::string& id, const std::string& path)
{
	if (!PathValidator::validate(path, FileType::TEXTURE))
	{
		std::cout << "TextureManager: Stopped loading texture with ID: " << id << " due to the invalid path!" << std::endl;
		return;
	}

	std::thread([this, id, path]()
		{
			Texture texture;
			if (!texture.loadFromFile(path))
			{
				std::cout << "ERROR: Failed to load texture with ID: " << id << " (file might me corrupt)." << std::endl;
				return;
			}

			std::lock_guard<std::mutex> lock(textureMtx);
			textures[id] = std::move(texture);

		}).detach();

}

Texture& TextureManager::getTexture(const std::string& id)
{
	std::lock_guard<std::mutex> lock(textureMtx);

	return textures.at(id);
}

bool TextureManager::isLoaded(const std::string& id)
{
	std::lock_guard<std::mutex> lock(textureMtx);
	return textures.count(id) > 0;
}
