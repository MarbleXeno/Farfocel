#include "Resource/ResourceManager.hpp"

fr::ResourceManager::ResourceManager()
{
}

fr::ResourceManager::~ResourceManager()
{
}

void fr::ResourceManager::loadImage(const std::string& id, const std::string& directoryToAsset)
{
	std::unique_ptr<sf::Image> image = std::make_unique<sf::Image>();
	if (!image->loadFromFile(directoryToAsset))
	{
		
	}
	m_image_manager.add<sf::Image>(id, std::move(image));
}

void fr::ResourceManager::loadTexture(const std::string& id, const std::string& directoryToAsset)
{
	std::unique_ptr<sf::Texture> texture = std::make_unique<sf::Texture>();
	if (!texture->loadFromFile(directoryToAsset))
	{
		std::cout << "Couldnt load\n";
	}
	m_texture_manager.add<sf::Texture>(id, std::move(texture));
}

void fr::ResourceManager::loadFont(const std::string& id, const std::string& directoryToAsset)
{
	std::unique_ptr<sf::Font> font = std::make_unique<sf::Font>();
	if (!font->loadFromFile(directoryToAsset))
	{
		std::cout << "Couldnt load\n";
	}
	m_font_manager.add<sf::Font>(id, std::move(font));
}

void fr::ResourceManager::loadMusic(const std::string& id, const std::string& directoryToAsset)
{
	std::unique_ptr<sf::Music> music = std::make_unique<sf::Music>();
	if (!music->openFromFile(directoryToAsset))
	{
		std::cout << "Couldnt load\n";
	}
	m_music_manager.add<sf::Music>(id, std::move(music));
}

void fr::ResourceManager::loadSound(const std::string& id, const std::string& directoryToAsset)
{
	sf::SoundBuffer soundBuffer;
	if (!soundBuffer.loadFromFile(directoryToAsset))
	{
		std::cout << "Couldnt load\n";
	}
	std::unique_ptr<sf::Sound> sound = std::make_unique<sf::Sound>();
	sound->setBuffer(soundBuffer);
	m_sound_manager.add<sf::Sound>(id, std::move(sound));
}

void fr::ResourceManager::loadTextureAtlas(const std::string& id, const sf::Texture& texture,
	const sf::Vector2u& frameCountPerAxis)
{
	std::unique_ptr<fr::TextureAtlas> textureAtlas = std::make_unique<fr::TextureAtlas>(texture, frameCountPerAxis);
	m_texture_atlas_manager.add<fr::TextureAtlas>(id, std::move(textureAtlas));
}
