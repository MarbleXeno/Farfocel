#include "Farfocel/Common/ResourceManager.hpp"

fr::ResourceManager::ResourceManager()
{
}

fr::ResourceManager::~ResourceManager()
{
}

sf::Image& fr::ResourceManager::LoadImage(const std::string& id, const std::string& directoryToAsset)
{
	sf::Image* image = new sf::Image();
	if (!image->loadFromFile(directoryToAsset))
	{
		std::cout << "void fr::ResourcesManager::LoadImage(const std::string& id, const std::string& directoryToAsset) --> couldn't load an image with given directory\n";
		imageStorer.Add<sf::Image>(id, new sf::Image);
	}

	imageStorer.Add<sf::Image>(id, image);
	return *imageStorer.Get(id);
}

sf::Texture& fr::ResourceManager::LoadTexture(const std::string& id, const std::string& directoryToAsset)
{
	sf::Texture* texture = new sf::Texture();
	if (!texture->loadFromFile(directoryToAsset))
	{
		std::cout << "void fr::ResourcesManager::LoadTexture(const std::string& id, const std::string& directoryToAsset) --> couldn't load a texture with given directory\n";
		textureStorer.Add<sf::Texture>(id, new sf::Texture);
	}

	textureStorer.Add<sf::Texture>(id, texture);
	return *textureStorer.Get(id);
}

sf::Font& fr::ResourceManager::LoadFont(const std::string& id, const std::string& directoryToAsset)
{
	sf::Font* font = new sf::Font();
	if (!font->loadFromFile(directoryToAsset))
	{
		std::cout << "void fr::ResourcesManager::LoadFont(const std::string& id, const std::string& directoryToAsset) --> couldn't load a font with given directory\n";
		fontStorer.Add<sf::Font>(id, new sf::Font);
	}
	fontStorer.Add<sf::Font>(id, font);
	return *fontStorer.Get(id);
}

sf::Music& fr::ResourceManager::LoadMusic(const std::string& id, const std::string& directoryToAsset)
{
	sf::Music* music = new sf::Music();
	if (!music->openFromFile(directoryToAsset))
	{
		std::cout << "void fr::ResourcesManager::LoadMusic(const std::string& id, const std::string& directoryToAsset) --> couldn't load a music with given directory\n";
		musicStorer.Add<sf::Music>(id, new sf::Music);
	}
	musicStorer.Add<sf::Music>(id, music);
	return *musicStorer.Get(id);
}

sf::Sound& fr::ResourceManager::LoadSound(const std::string& id, const std::string& directoryToAsset)
{
	sf::SoundBuffer soundBuffer;
	if (!soundBuffer.loadFromFile(directoryToAsset))
	{
		std::cout << "void fr::ResourcesManager::LoadSound(const std::string& id, const std::string& directoryToAsset) --> couldn't load a sound with given directory\n";
		soundStorer.Add<sf::Sound>(id, new sf::Sound);
	}
	sf::Sound* sound = new sf::Sound();
	sound->setBuffer(soundBuffer);
	soundStorer.Add<sf::Sound>(id, sound);
	return *soundStorer.Get(id);
}

sf::Sprite &fr::ResourceManager::LoadSprite(const std::string &id, const std::string &directoryToAsset)
{
    sf::Sprite* sprite = new sf::Sprite();
    sprite->setTexture(LoadTexture(id, directoryToAsset));
    spriteStorer.Add<sf::Sprite>(id, sprite);
    return *spriteStorer.Get(id);
}

fru::TextureAtlas& fr::ResourceManager::LoadTextureAtlas(const std::string& id, const std::string& directoryToAsset, const sf::Vector2u& framesPerAxis)
{

	fru::TextureAtlas* textureAtlas = new fru::TextureAtlas(LoadTexture(id, directoryToAsset), framesPerAxis);
	textureAtlasStorer.Add<fru::TextureAtlas>(id, textureAtlas);
	return *textureAtlasStorer.Get(id);
}

sf::Sprite &fr::ResourceManager::LoadSprite(const std::string &id, sf::Texture &texture) {
    sf::Sprite* sprite = new sf::Sprite();
    sprite->setTexture(texture);
    spriteStorer.Add<sf::Sprite>(id, sprite);
    return *spriteStorer.Get(id);
}

sf::Image& fr::ResourceManager::GetImage(const std::string& id)
{
	return *imageStorer.Get(id);
}

sf::Texture& fr::ResourceManager::GetTexture(const std::string& id)
{
	return *textureStorer.Get(id);
}

sf::Font& fr::ResourceManager::GetFont(const std::string& id)
{
	return *fontStorer.Get(id);
}

sf::Music& fr::ResourceManager::GetMusic(const std::string& id)
{
	return *musicStorer.Get(id);
}

sf::Sound& fr::ResourceManager::GetSound(const std::string& id)
{
	return *soundStorer.Get(id);
}

sf::Sprite& fr::ResourceManager::GetSprite(const std::string &id) {
    return *spriteStorer.Get(id);
}

fru::TextureAtlas& fr::ResourceManager::GetTextureAtlas(const std::string& id)
{
	return *textureAtlasStorer.Get(id);
}
