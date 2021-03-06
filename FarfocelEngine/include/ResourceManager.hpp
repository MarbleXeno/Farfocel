/*
	Name:
	ResourceManager

	Description:
	A wrapper around Asset.hpp; Loads, stores and manages app assets.
*/

#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Asset.hpp"
#include "TextureAtlas.hpp"
namespace fr
{
	class ResourceManager
	{
	public:
		ResourceManager();
		~ResourceManager();

		void loadImage(const std::string& id, const std::string& directoryToAsset);
		void loadTexture(const std::string& id, const std::string& directoryToAsset);
		void loadFont(const std::string& id, const std::string& directoryToAsset);
		void loadMusic(const std::string& id, const std::string& directoryToAsset);
		void loadSound(const std::string& id, const std::string& directoryToAsset);

        void loadTextureAtlas(const std::string& id, const sf::Texture& texture, const sf::Vector2u& frameCountPerAxis);

		std::shared_ptr<sf::Image> getImage(const std::string& id)
		{
			return m_imageManager.get<sf::Image>(id);
		}
		std::shared_ptr<sf::Texture> getTexture(const std::string& id)
		{
			return m_textureManager.get<sf::Texture>(id);
		}
		std::shared_ptr<sf::Font> getFont(const std::string& id)
		{
			return m_fontManager.get<sf::Font>(id);
		}
		std::shared_ptr<sf::Music> getMusic(const std::string& id)
		{
			return m_musicManager.get<sf::Music>(id);
		}
		std::shared_ptr<sf::Sound> getSound(const std::string& id)
		{
			return m_soundManager.get<sf::Sound>(id);
		}

        std::shared_ptr<fr::TextureAtlas> getTextureAtlas(const std::string& id)
        {
            return m_textureAtlasManager.get<fr::TextureAtlas>(id);
        }
	private:
		fr_util::AssetManager<sf::Image> m_imageManager;
		fr_util::AssetManager<sf::Texture> m_textureManager;
		fr_util::AssetManager<sf::Font> m_fontManager;
		fr_util::AssetManager<sf::Music> m_musicManager;
		fr_util::AssetManager<sf::Sound> m_soundManager;

        fr_util::AssetManager<fr::TextureAtlas> m_textureAtlasManager;
	};
}