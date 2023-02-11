#pragma once
#include <unordered_map>
#include <SFML/Graphics.hpp>
#include <iostream>

namespace fru {
	class TextureAtlas {
	public:
		TextureAtlas();
		TextureAtlas(sf::Texture& atlas, const sf::Vector2u& framesPerAxis);
		~TextureAtlas();

		void SetFrameCount(const std::uint64_t& frames);
		const sf::IntRect& GetTextureRect(const std::uint64_t& frame);

		sf::Texture* GetTexture();

	private:
		void CalculateFrameRect();

		sf::Texture* mTexture;
		sf::Vector2u mFramesPerAxis;

		std::uint64_t mFrameCount;
		sf::Vector2u mFrameSize;

		std::unordered_map<uint64_t, sf::IntRect> mFrameRect;

	};
}