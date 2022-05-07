/*
    Name:
    AnimationManager

    Description:
    Stores and manages in an eficient way different animations.
*/

#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <unordered_map>

#include "Animation.hpp"
#include "TextureAtlas.hpp"

namespace fr
{
	class AnimationManager
	{
    public:
        AnimationManager();

        AnimationManager(sf::RenderWindow& renderWindow);

        ~AnimationManager();

        void add(const std::string& id, sf::Sprite& sprite, fr::TextureAtlas& textureAtlas);
        void init(const std::string& id, const float& oneCycleDuration, const bool& repeat, const uint64_t& startingFrame, const uint64_t& endingFrame);
        
        void update(const float deltaTime);
        void draw();
        void changeAnimationState(const std::string& id, const AnimationState state);


    private:
        std::unordered_map<std::string, fr_util::Animation> m_animations;

        sf::RenderWindow* m_renderWindow = nullptr;
	};
}