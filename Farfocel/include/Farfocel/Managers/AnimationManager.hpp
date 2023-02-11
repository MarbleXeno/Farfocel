#pragma once
#include <unordered_map>
#include <iostream>
#include "Farfocel/Utils/Animation.hpp"
#include "Farfocel/Core/Renderer.hpp"
#include "Farfocel/Managers/ResourcesManager.hpp"

namespace fr {
	class AnimationManager {
	public:
		AnimationManager();
		AnimationManager(fr::Renderer& renderer);
		~AnimationManager();

		void AddTextureAtlas(const std::string& id, fru::TextureAtlas& textureAtlas);

		void Add(const std::string& id, sf::Sprite& sprite, const std::string& idTextureAtlas, const uint64_t& startingFrame, const uint64_t& endingFrame, const float& switchTime, const bool& repeat);
		void Remove(const std::string& id);

		fru::Animation* Get(const std::string& id);

		void Update();

	private:
		std::unordered_map<std::string, fru::TextureAtlas> mTextureAtlases;
		std::unordered_map<std::string, fru::Animation> mAnimations;

		std::vector<std::string> mTextureAtlasesToRemove;
		std::vector<std::string> mAnimationsToRemove;


		fr::Renderer* mRenderer;
	};
}