#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Farfocel/Utils/AssetStorer.hpp"
#include "Farfocel/Utils/TextureAtlas.hpp"
namespace fr {
	class ResourceManager {
	public:
		ResourceManager();
		~ResourceManager();

        sf::Image& LoadImage(const std::string& id, const std::string& directoryToAsset);
        sf::Texture& LoadTexture(const std::string& id, const std::string& directoryToAsset);
        sf::Font& LoadFont(const std::string& id, const std::string& directoryToAsset);
        sf::Music& LoadMusic(const std::string& id, const std::string& directoryToAsset);
		sf::Sound& LoadSound(const std::string& id, const std::string& directoryToAsset);
        sf::Sprite& LoadSprite(const std::string& id, const std::string& directoryToAsset);
        sf::Sprite& LoadSprite(const std::string& id, sf::Texture& texture);


		fru::TextureAtlas& LoadTextureAtlas(const std::string& id, const std::string& directoryToAsset, const sf::Vector2u& framesPerAxis);

		sf::Image& GetImage(const std::string& id);
        sf::Texture& GetTexture(const std::string& id);
		sf::Font& GetFont(const std::string& id);
		sf::Music& GetMusic(const std::string& id);
        sf::Sound& GetSound(const std::string& id);
        sf::Sprite& GetSprite(const std::string& id);
		fru::TextureAtlas& GetTextureAtlas(const std::string& id);

		fru::AssetStorer<sf::Image> imageStorer;
		fru::AssetStorer<sf::Texture> textureStorer;
		fru::AssetStorer<sf::Font> fontStorer;
		fru::AssetStorer<sf::Music> musicStorer;
		fru::AssetStorer<sf::Sound> soundStorer;
        fru::AssetStorer<sf::Sprite> spriteStorer;
        fru::AssetStorer<fru::TextureAtlas> textureAtlasStorer;

	};
}