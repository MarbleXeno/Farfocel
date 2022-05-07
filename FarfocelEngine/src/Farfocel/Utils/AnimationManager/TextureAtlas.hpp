/*
    Name:
    TextureAtlas

    Description:
    A custom Farfocel Asset. Stores and manages different texture rects based on the given texture atlas/sprite sheet.

    Used by:
    ResourceManager,
    AnimationManager,
    Animation
*/

#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>

#include "../Log.hpp"


namespace fr
{
    class TextureAtlas
    {
    public:
        TextureAtlas(const sf::Texture& texture, const sf::Vector2u& maxFramesPerAxis)
        :   m_texture(&texture), m_frameCountPerAxis(maxFramesPerAxis)
        {
            m_totalFrameCount = m_frameCountPerAxis.x * m_frameCountPerAxis.y;
            m_frameSize = {m_texture->getSize().x / m_frameCountPerAxis.x, m_texture->getSize().y / m_frameCountPerAxis.y};

            calcFrameRect();
        }

        ~TextureAtlas()
        {

        }

        // if the texture atlas is not even
        void setCustomFrameCount(const std::uint64_t frames)
        {
            m_totalFrameCount = frames;

            calcFrameRect();
        }

        const sf::IntRect getFrameTextureRect(const std::uint64_t frameIndex)
        {
            std::uint64_t frame = frameIndex;

            if (frame == 0)
                frame++;
            if (frame > m_totalFrameCount)
            {
                fr::Log::printDebug(fr::LogColor::Red, true, "TextureAtlas: getFrameTextureRect -> Given frame parameter is greater than the total amount of frames in the texture atlas");
                return sf::IntRect({ 0,0 }, { 0,0 });
            }

            return m_frameRect[frame];
        }

        // standard getters below
        const sf::Texture& getTexture() { return *m_texture; }
        const sf::Vector2u& getFrameSize() { return m_frameSize; }
        const std::uint64_t& getTotalFrameCount() { return m_totalFrameCount; }
        const sf::Vector2u& getFrameCountPerAxis() { return m_frameCountPerAxis; }

    private:
        void calcFrameRect()
        {
            std::uint64_t frameIndex = 1;
            for (std::uint32_t column = 0; column < m_frameCountPerAxis.y; ++column)
            {
                for (std::uint32_t row = 0; row < m_frameCountPerAxis.x; ++row)
                {
                    if (frameIndex > m_totalFrameCount)
                        return;

                    m_frameRect[frameIndex] = sf::IntRect(row * m_frameSize.x, column * m_frameSize.y, m_frameSize.x, m_frameSize.y);
                    frameIndex++;
                }
            }
        }

        const sf::Texture* m_texture = nullptr;

        sf::Vector2u m_frameCountPerAxis = {0, 0};
        std::uint64_t m_totalFrameCount = 0;
        sf::Vector2u m_frameSize = {0, 0};

        std::unordered_map<uint64_t, sf::IntRect> m_frameRect;
    };
}