
#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "AssetStorer.hpp"
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
			return m_image_manager.get<sf::Image>(id);
		}
		std::shared_ptr<sf::Texture> getTexture(const std::string& id)
		{
			return m_texture_manager.get<sf::Texture>(id);
		}
		std::shared_ptr<sf::Font> getFont(const std::string& id)
		{
			return m_font_manager.get<sf::Font>(id);
		}
		std::shared_ptr<sf::Music> getMusic(const std::string& id)
		{
			return m_music_manager.get<sf::Music>(id);
		}
		std::shared_ptr<sf::Sound> getSound(const std::string& id)
		{
			return m_sound_manager.get<sf::Sound>(id);
		}

		std::shared_ptr<fr::TextureAtlas> getTextureAtlas(const std::string& id)
		{
			return m_texture_atlas_manager.get<fr::TextureAtlas>(id);
		}

	private:
		fru::AssetManager<sf::Image> m_image_manager;
		fru::AssetManager<sf::Texture> m_texture_manager;
		fru::AssetManager<sf::Font> m_font_manager;
		fru::AssetManager<sf::Music> m_music_manager;
		fru::AssetManager<sf::Sound> m_sound_manager;

		fru::AssetManager<fr::TextureAtlas> m_texture_atlas_manager;
	};
}