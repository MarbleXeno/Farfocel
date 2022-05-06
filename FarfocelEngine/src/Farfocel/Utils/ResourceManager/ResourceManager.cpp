#include "ResourceManager.hpp"

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
		fr::Log::printDebug(fr::LogColor::Red, true, "ResourceManager: loadImage -> Couldn't find the file in a given directory: " + directoryToAsset + "\n");
	}
	m_imageManager.add<sf::Image>(id, std::move(image));
}

void fr::ResourceManager::loadTexture(const std::string& id, const std::string& directoryToAsset)
{
	std::unique_ptr<sf::Texture> texture = std::make_unique<sf::Texture>();
	if (!texture->loadFromFile(directoryToAsset))
	{
		fr::Log::printDebug(fr::LogColor::Red, true, "ResourceManager: loadTexture -> Couldn't find the file in a given directory: " + directoryToAsset + "\n");
	}
	m_textureManager.add<sf::Texture>(id, std::move(texture));
}

void fr::ResourceManager::loadFont(const std::string& id, const std::string& directoryToAsset)
{
	std::unique_ptr<sf::Font> font = std::make_unique<sf::Font>();
	if (!font->loadFromFile(directoryToAsset))
	{
		fr::Log::printDebug(fr::LogColor::Red, true, "ResourceManager: loadFont -> Couldn't find the file in a given directory: " + directoryToAsset + "\n");
	}
	m_fontManager.add<sf::Font>(id, std::move(font));
}

void fr::ResourceManager::loadMusic(const std::string& id, const std::string& directoryToAsset)
{
	std::unique_ptr<sf::Music> music = std::make_unique<sf::Music>();
	if(!music->openFromFile(directoryToAsset))
	{
		fr::Log::printDebug(fr::LogColor::Red, true, "ResourceManager: loadMusic -> Couldn't find the file in a given directory: " + directoryToAsset + "\n");
	}
	m_musicManager.add<sf::Music>(id, std::move(music));
}

void fr::ResourceManager::loadSound(const std::string& id, const std::string& directoryToAsset)
{
	sf::SoundBuffer soundBuffer;
	if (!soundBuffer.loadFromFile(directoryToAsset))
	{
		fr::Log::printDebug(fr::LogColor::Red, true, "ResourceManager: loadSound -> Couldn't find the file in a given directory: " + directoryToAsset + "\n");
	}
	std::unique_ptr<sf::Sound> sound = std::make_unique<sf::Sound>();
	sound->setBuffer(soundBuffer);
	m_soundManager.add<sf::Sound>(id, std::move(sound));
}

void fr::ResourceManager::loadTextureAtlas(const std::string &id, const sf::Texture &texture,
                                           const sf::Vector2u &frameCountPerAxis)
{
    std::unique_ptr<fr::TextureAtlas> textureAtlas = std::make_unique<fr::TextureAtlas>(texture, frameCountPerAxis);
    m_textureAtlasManager.add<fr::TextureAtlas>(id, std::move(textureAtlas));
}
