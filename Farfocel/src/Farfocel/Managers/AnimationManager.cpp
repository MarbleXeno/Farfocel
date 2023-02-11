#include "Farfocel/Managers/AnimationManager.hpp"

fr::AnimationManager::AnimationManager()
	: mRenderer(nullptr)
{
}

fr::AnimationManager::AnimationManager(fr::Renderer& renderer)
	: mRenderer(&renderer)
{
}

fr::AnimationManager::~AnimationManager()
{
}

void fr::AnimationManager::AddTextureAtlas(const std::string& id, fru::TextureAtlas& textureAtlas)
{
	if (mTextureAtlases.count(id)) {
		std::cout << "void fr::AnimationManager::AddTextureAtlas(const std::string& id, fru::TextureAtlas& textureAtlas) --> Couldn't add a texture atlas because given id is already occupied\n";
		return;
	}

	if (!textureAtlas.GetTexture()) {
		std::cout << "void fr::AnimationManager::AddTextureAtlas(const std::string& id, fru::TextureAtlas& textureAtlas) --> Couldn't add a texture atlas because given one doesn't have a texture loaded to it\n";
		return;
	}

	mTextureAtlases[id] = textureAtlas;
}

void fr::AnimationManager::Add(const std::string& id, sf::Sprite& sprite, const std::string& idTextureAtlas, const uint64_t& startingFrame, const uint64_t& endingFrame, const float& switchTime, const bool& repeat)
{
	if (mAnimations.count(id)) {
		std::cout << "void fr::AnimationManager::Add(const std::string& id, sf::Sprite& sprite, const std::string& idTextureAtlas, const uint64_t& startingFrame, const uint64_t& endingFrame, const float& switchTime, const bool& repeat) --> Couldn't add an animation because given id is already occupied\n";
		return;
	}
	
	if (!mTextureAtlases.count(idTextureAtlas)) {
		std::cout << "void fr::AnimationManager::Add(const std::string& id, sf::Sprite& sprite, const std::string& idTextureAtlas, const uint64_t& startingFrame, const uint64_t& endingFrame, const float& switchTime, const bool& repeat) --> Couldn't add an animation because given texture atlas id doesn't exist. Before adding it load the texture atlas first\n";
		return;
	}

	mAnimations[id] = fru::Animation(sprite, mTextureAtlases[idTextureAtlas]);
	mAnimations[id].Init(switchTime, repeat, startingFrame, endingFrame);
	mAnimations[id].Start();

}

void fr::AnimationManager::Remove(const std::string& id)
{
	if (!mAnimations.count(id)) {
		std::cout << "void fr::AnimationManager::Remove(const std::string& id) --> Couldn't remove an animation because given id doesn't exist\n";
		return;
	}
	mAnimationsToRemove.push_back(id);
}

fru::Animation* fr::AnimationManager::Get(const std::string& id)
{
	if (!mAnimations.count(id)) {
		std::cout << "fru::Animation* fr::AnimationManager::Get(const std::string& id) --> Couldn't get an animation because given id doesn't exist\n";
		return nullptr;
	}

	return &mAnimations[id];
}

void fr::AnimationManager::Update()
{
	for (auto& [id, animation] : mAnimations){
		if (animation.GetState() == fru::AnimationState::Started) {	
			animation.Update(mRenderer->GetDeltaTimeFloat());
		}
	}

	for (auto key : mAnimationsToRemove) {
		mAnimations.erase(key);
	}
	mAnimationsToRemove.clear();
}