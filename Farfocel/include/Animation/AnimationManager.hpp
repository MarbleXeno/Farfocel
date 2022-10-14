#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <unordered_map>

#include "Animation.hpp"
#include "Resource/TextureAtlas.hpp"

namespace fr
{
    class AnimationManager
    {
    public:
        AnimationManager();

        AnimationManager(sf::RenderWindow& render_window);

        ~AnimationManager();

        void add(const std::string& id, sf::Sprite& sprite, fr::TextureAtlas& texture_atlas);
        void init(const std::string& id, const float& one_cycle_duration, const bool& repeat, const uint64_t& starting_frame, const uint64_t& ending_frame);

        fru::Animation& get(const std::string& id) { return m_animations[id]; }

        void update(const float deltaTime);
        void draw();
        void changeAnimationState(const std::string& id, const AnimationState state);

    private:
        std::unordered_map<std::string, fru::Animation> m_animations;

        sf::RenderWindow* m_render_window = nullptr;
    };
}