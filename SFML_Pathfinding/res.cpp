#include "res.h"

std::unordered_map<std::string, sf::Font> res_mgr::fonts;
std::unordered_map<std::string, sf::Texture> res_mgr::textures;

sf::Font res_mgr::defaultFont;
sf::Texture res_mgr::defaultTexture;

bool res_mgr::fontExists(const std::string& name) 
{
	return fonts.find(name) != fonts.end();
}
bool res_mgr::textureExists(const std::string& name)
{
	return textures.find(name) != textures.end();
}

sf::Font& res_mgr::getFont(const std::string& name) 
{
	if (!fontExists(name)) 
	{
		return defaultFont;
	}

	return fonts.at(name);
}
sf::Texture& res_mgr::getTexture(const std::string& name)
{
	if (!textureExists(name))
	{
		return defaultTexture;
	}

	return textures.at(name);
}

void res_mgr::addFont(const std::string& path, const std::string& name)
{
	sf::Font font;

	if (font.loadFromFile(path)) 
	{
		fonts.insert(std::make_pair(name, font));
	}
	else 
	{
		fonts.insert(std::make_pair(name, defaultFont));
	}
}
void res_mgr::addTexture(const std::string& path, const std::string& name)
{
	sf::Texture texture;

	if (texture.loadFromFile(path)) 
	{
		textures.insert(std::make_pair(name, texture));
	}
	else 
	{
		textures.insert(std::make_pair(name, defaultTexture));
	}
}

void res_mgr::setDefaultFont(const std::string& path, const std::string& name)
{
	sf::Font font;

	if (font.loadFromFile(path)) 
	{
		defaultFont = font;
	}
	else 
	{
		LOG("res_mgr: default font at \"%s\" could not be loaded.\n", path);
	}
}
void res_mgr::setDefaultTexture(const std::string& path, const std::string& name)
{
	sf::Texture texture;

	if (texture.loadFromFile(path)) 
	{
		defaultTexture = texture;
	}
	else 
	{
		LOG("res_mgr: default texture at \"%s\" could not be loaded.\n", path);
	}
}
