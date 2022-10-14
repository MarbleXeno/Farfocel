#include "Animation/AnimationManager.hpp"

fr::AnimationManager::AnimationManager()
{

}

fr::AnimationManager::AnimationManager(sf::RenderWindow& render_window)
    : m_render_window(&render_window)
{

}

fr::AnimationManager::~AnimationManager()
{
}

void fr::AnimationManager::add(const std::string& id, sf::Sprite& sprite, fr::TextureAtlas& textureAtlas)
{
    m_animations[id] = fru::Animation(sprite, textureAtlas);
}

void fr::AnimationManager::init(const std::string& id, const float& oneCycleDuration, const bool& repeat, const uint64_t& startingFrame, const uint64_t& endingFrame)
{
    if (!m_animations.count(id))
    {
        std::cout << "Couldnt load\n";
        return;
    }
    m_animations[id].init(oneCycleDuration, repeat, startingFrame, endingFrame);
    m_animations[id].applyTextureToSprite();
    m_animations[id].setAnimationState(fr::AnimationState::Playing);
}

void fr::AnimationManager::update(const float deltaTime)
{
    auto it = m_animations.begin();
    auto next_it = it;

    while (it != m_animations.end())
    {
        ++next_it;
        if (it->second.getAnimationState() == AnimationState::MarkedForRemoval)
        {
            m_animations.erase(it);
        }
        else
        {
            if (it->second.getAnimationState() == AnimationState::Unfocused)
                it->second.applyTextureToSprite();

            it->second.play(deltaTime);
        }
        it = next_it;
    }
}

void fr::AnimationManager::changeAnimationState(const std::string& id, const AnimationState state)
{
    if (!m_animations.count(id))
    {
        return;
    }
    m_animations[id].setAnimationState(state);
}

void fr::AnimationManager::draw()
{
    if (m_render_window)
    {
        std::unordered_map<std::string, fru::Animation>::iterator it = m_animations.begin();

        while (it != m_animations.end())
        {
            m_render_window->draw(it->second);

            it++;
        }
    }
}