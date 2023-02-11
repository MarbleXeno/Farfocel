#include "Farfocel/Utils/Animation.hpp"

fru::Animation::Animation()
{
}

fru::Animation::Animation(sf::Sprite& sprite, fru::TextureAtlas& textureAtlas)
	:	mSprite(&sprite), mTextureAtlas(&textureAtlas)
{

}

fru::Animation::~Animation()
{
}

void fru::Animation::Init(const uint16_t& FPS, const bool& repeat, const uint64_t& startingFrame, const uint64_t& endingFrame)
{
	mFPS = FPS;
	mRepeat = repeat;
	mStartingFrame = startingFrame;
	mEndingFrame = endingFrame;
	mInitialized = true;
}

void fru::Animation::ChangeFPS(const uint16_t& FPS)
{
	mFPS = FPS;
}

void fru::Animation::Start()
{
	if (!mInitialized) {
		std::cout << "void fru::Animation::Start() --> Animation is not initialized\n";
		return;
	}

	mSprite->setTexture(*mTextureAtlas->GetTexture());
	mSprite->setTextureRect(mTextureAtlas->GetTextureRect(mStartingFrame));
	mCurrentFrame++;
	mState = fru::AnimationState::Started;
}

void fru::Animation::Pause()
{
	mState = fru::AnimationState::Paused;
}

void fru::Animation::Reset()
{
	mState = fru::AnimationState::Paused;

	mDuration = 0.f;
	mElapsedTime = 0.f;
	
	Start();
}

void fru::Animation::Update(const float& deltaTime)
{
	mDeltaTime = deltaTime;
	if (mState != fru::AnimationState::Started) { return; }

	mElapsedTime += mDeltaTime;


	if (mElapsedTime >= mFPS*mDeltaTime) {
		mDuration += mElapsedTime;
		mCurrentFrame++;

		if (!mRepeat && mCurrentFrame > mEndingFrame) {
			Pause();
			return;
		}
		else if (mCurrentFrame > mEndingFrame) {
			mCurrentFrame = mStartingFrame;
		}

		mSprite->setTextureRect(mTextureAtlas->GetTextureRect(mCurrentFrame));
		
		mElapsedTime = 0.f;
	}
}

const fru::AnimationState& fru::Animation::GetState()
{
	return mState;
}
