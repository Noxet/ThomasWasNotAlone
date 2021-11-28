#include "tpch.hpp"

#include "TextureHolder.hpp"

#include <iostream>


sf::Texture& TextureHolder::getTexture(const std::string& filename)
{
	/*
	 * Get a texture from a filename.
	 * If the texture is not loaded, then load it and store
	 */
	auto& textures = getInstance().m_textures;

	const auto keyValuePair = textures.find(filename);

	if (keyValuePair != textures.end())
	{
		// match found, return the texture
		return keyValuePair->second;
	}
	
	auto& texture = textures[filename];
	if (!texture.loadFromFile(filename))
	{
		std::cout << "Warning, could not load texture file: " << filename << std::endl;
	}

	return texture;
}
