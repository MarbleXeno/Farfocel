#include "Farfocel/Managers/ResourcesManager.hpp"

fr::ResourcesManager::ResourcesManager()
{
}

fr::ResourcesManager::~ResourcesManager()
{
}

const bool fr::ResourcesManager::LoadImage(const std::string& id, const std::string& directoryToAsset)
{
	sf::Image* image = new sf::Image();
	if (!image->loadFromFile(directoryToAsset))
	{
		std::cout << "void fr::ResourcesManager::LoadImage(const std::string& id, const std::string& directoryToAsset) --> couldn't load an image with given directory\n";
		imageStorer.Add<sf::Image>(id, new sf::Image);
		return false;
	}

	imageStorer.Add<sf::Image>(id, image);
	return true;
}

const bool fr::ResourcesManager::LoadTexture(const std::string& id, const std::string& directoryToAsset)
{
	sf::Texture* texture = new sf::Texture();
	if (!texture->loadFromFile(directoryToAsset))
	{
		std::cout << "void fr::ResourcesManager::LoadTexture(const std::string& id, const std::string& directoryToAsset) --> couldn't load a texture with given directory\n";
		textureStorer.Add<sf::Texture>(id, new sf::Texture);
		return false;
	}

	textureStorer.Add<sf::Texture>(id, texture);
	return true;
}

const bool fr::ResourcesManager::LoadFont(const std::string& id, const std::string& directoryToAsset)
{
	sf::Font* font = new sf::Font();
	if (!font->loadFromFile(directoryToAsset))
	{
		std::cout << "void fr::ResourcesManager::LoadFont(const std::string& id, const std::string& directoryToAsset) --> couldn't load a font with given directory\n";
		fontStorer.Add<sf::Font>(id, new sf::Font);
		return false;
	}
	fontStorer.Add<sf::Font>(id, font);
	return true;
}

const bool fr::ResourcesManager::LoadMusic(const std::string& id, const std::string& directoryToAsset)
{
	sf::Music* music = new sf::Music();
	if (!music->openFromFile(directoryToAsset))
	{
		std::cout << "void fr::ResourcesManager::LoadMusic(const std::string& id, const std::string& directoryToAsset) --> couldn't load a music with given directory\n";
		musicStorer.Add<sf::Music>(id, new sf::Music);
		return false;
	}
	musicStorer.Add<sf::Music>(id, music);
	return true;
}

const bool fr::ResourcesManager::LoadSound(const std::string& id, const std::string& directoryToAsset)
{
	sf::SoundBuffer soundBuffer;
	if (!soundBuffer.loadFromFile(directoryToAsset))
	{
		std::cout << "void fr::ResourcesManager::LoadSound(const std::string& id, const std::string& directoryToAsset) --> couldn't load a sound with given directory\n";
		soundStorer.Add<sf::Sound>(id, new sf::Sound);
		return false;
	}
	sf::Sound* sound = new sf::Sound();
	sound->setBuffer(soundBuffer);
	soundStorer.Add<sf::Sound>(id, sound);
	return true;
}

const bool fr::ResourcesManager::LoadTextureAtlas(const std::string& id, const std::string& directoryToAsset, const sf::Vector2u& framesPerAxis)
{
	if (!LoadTexture(id, directoryToAsset)) {
		std::cout << "void fr::ResourcesManager::LoadTextureAtlas(const std::string& id, const std::string& directoryToAsset, const sf::Vector2u& framesPerAxis) --> couldn't load a texture atlas with given directory\n";
		textureAtlasStorer.Add<fru::TextureAtlas>(id, new fru::TextureAtlas());
		return false;
	}

	fru::TextureAtlas* textureAtlas = new fru::TextureAtlas(*GetTexture(id), framesPerAxis);
	textureAtlasStorer.Add<fru::TextureAtlas>(id, textureAtlas);
	return true;
}

sf::Image* fr::ResourcesManager::GetImage(const std::string& id)
{
	return imageStorer.Get(id);
}

sf::Texture* fr::ResourcesManager::GetTexture(const std::string& id)
{
	return textureStorer.Get(id);
}

sf::Font* fr::ResourcesManager::GetFont(const std::string& id)
{
	return fontStorer.Get(id);
}

sf::Music* fr::ResourcesManager::GetMusic(const std::string& id)
{
	return musicStorer.Get(id);
}

sf::Sound* fr::ResourcesManager::GetSound(const std::string& id)
{
	return soundStorer.Get(id);
}

fru::TextureAtlas* fr::ResourcesManager::GetTextureAtlas(const std::string& id)
{
	return textureAtlasStorer.Get(id);
}
