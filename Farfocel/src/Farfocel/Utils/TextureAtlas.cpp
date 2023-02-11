#include "Farfocel/Utils/TextureAtlas.hpp"

fru::TextureAtlas::TextureAtlas()
	:	mTexture(nullptr), mFramesPerAxis(1,1), mFrameCount(0), mFrameSize(0,0)
{
}

fru::TextureAtlas::TextureAtlas(sf::Texture& atlas, const sf::Vector2u& framesPerAxis)
	: mTexture(&atlas), mFramesPerAxis(framesPerAxis), mFrameCount(0), mFrameSize(0, 0)
{
	mFrameCount = mFramesPerAxis.x * mFramesPerAxis.y;
	mFrameSize = { mTexture->getSize().x / mFramesPerAxis.x, mTexture->getSize().y / mFramesPerAxis.y };
	CalculateFrameRect();
}

fru::TextureAtlas::~TextureAtlas()
{
}

void fru::TextureAtlas::SetFrameCount(const std::uint64_t& frames)
{
	mFrameCount = frames;
	CalculateFrameRect();
}

const sf::IntRect& fru::TextureAtlas::GetTextureRect(const std::uint64_t& frame)
{
	if (frame == 0) {
		std::cout << "const sf::IntRect& fru::TextureAtlas::GetTextureRect(std::uint64_t& frame) --> There's no frame with an index of zero. Returning the first frame rect\n";
		return mFrameRect[frame];
	}

	if (frame > mFrameCount) {
		std::cout << "const sf::IntRect& fru::TextureAtlas::GetTextureRect(std::uint64_t& frame) --> Given frame index is too big. Returning the last frame\n";
		return mFrameRect[mFrameCount];
	}

	return mFrameRect[frame];
}

sf::Texture* fru::TextureAtlas::GetTexture()
{
	return mTexture;
}

void fru::TextureAtlas::CalculateFrameRect()
{
	std::uint64_t frameIndex = 1;
	for (size_t y = 0; y < mFramesPerAxis.y; y++)
	{
		for (size_t x = 0; x < mFramesPerAxis.y; y++)
		{
			if (frameIndex > mFrameCount) { return; }
			mFrameRect[frameIndex] = sf::IntRect(x * mFrameSize.x, y * mFrameSize.y, mFrameSize.x, mFrameSize.y);
			frameIndex++;
		}
	}
}
