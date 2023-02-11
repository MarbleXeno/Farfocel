#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

#include "Farfocel/Utils/TextureAtlas.hpp"

namespace fru {
	enum class AnimationState {
		Unfocused = 0,
		Paused,
		Started
	};

	class Animation{
	public:
		Animation();
		Animation(sf::Sprite& sprite, fru::TextureAtlas& textureAtlas);
		~Animation();

		void Init(const uint16_t& FPS, const bool& repeat, const uint64_t& startingFrame, const uint64_t& endingFrame);
		void ChangeFPS(const uint16_t& FPS);

		void Start();
		void Pause();
		void Reset();

		void Update(const float& deltaTime);

		const fru::AnimationState& GetState();

	private:
		fru::AnimationState mState = fru::AnimationState::Unfocused;

		bool mInitialized = false;

		sf::Sprite* mSprite = nullptr;
		fru::TextureAtlas* mTextureAtlas = nullptr;

		bool mRepeat = false;
		uint32_t mCurrentFrame = 1;
		uint32_t mStartingFrame = 1;
		uint32_t mEndingFrame = 1;

		float mFPS = 0.f;
		float mDuration = 0.f;
		float mElapsedTime = 0.f;

		float mDeltaTime = 0.f;
	};
}