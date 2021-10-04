#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include <unordered_map>

#include "util.h"

class res_mgr 
{
private:

	static std::unordered_map<std::string, sf::Font> fonts;
	static std::unordered_map<std::string, sf::Texture> textures;

	static bool fontExists(const std::string& name);
	static bool textureExists(const std::string& name);

	static sf::Font defaultFont;
	static sf::Texture defaultTexture;

public:

	res_mgr() = delete;	

	static sf::Font& getFont(const std::string& name);
	static sf::Texture& getTexture(const std::string& name);
		  
	static void addFont(const std::string& path, const std::string& name);
	static void addTexture(const std::string& path, const std::string& name);

	static void setDefaultFont(const std::string& path, const std::string& name);
	static void setDefaultTexture(const std::string& path, const std::string& name);
};