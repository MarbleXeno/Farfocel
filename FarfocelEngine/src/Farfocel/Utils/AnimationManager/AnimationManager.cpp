#include "AnimationManager.hpp"

fr::AnimationManager::AnimationManager()
{

}

fr::AnimationManager::AnimationManager(sf::RenderWindow& renderWindow)
    :   m_renderWindow(&renderWindow)
{

}

fr::AnimationManager::~AnimationManager()
{
}

void fr::AnimationManager::add(const std::string& id, sf::Sprite& sprite, fr::TextureAtlas& textureAtlas)
{
	m_animations[id] = fr_util::Animation(sprite, textureAtlas);
}

void fr::AnimationManager::init(const std::string& id, const float& oneCycleDuration, const bool& repeat, const uint64_t& startingFrame, const uint64_t& endingFrame)
{
    if (!m_animations.count(id))
    {
        fr::Log::printDebug(fr::LogColor::Red, true, "AnimationManager: init -> Couldn't find '" + id + "'.");
        return;
    }
	m_animations[id].init(oneCycleDuration, repeat, startingFrame, endingFrame);
	m_animations[id].applyTextureToSprite();
    m_animations[id].setAnimationState(fr::AnimationState::Playing);
}

void fr::AnimationManager::update(const float deltaTime)
{
    std::unordered_map<std::string, fr_util::Animation>::iterator it = m_animations.begin();

    while (it != m_animations.end())
    {
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
        it++;
    }
}

void fr::AnimationManager::changeAnimationState(const std::string& id, const AnimationState state)
{
    if (!m_animations.count(id))
    {
        fr::Log::printDebug(fr::LogColor::Red, true, "AnimationManager: init -> Couldn't find '" + id + "'.");
        return;
    }
    m_animations[id].setAnimationState(state);
}

void fr::AnimationManager::draw()
{
    if (m_renderWindow)
    {
        std::unordered_map<std::string, fr_util::Animation>::iterator it = m_animations.begin();

        while (it != m_animations.end())
        {
            m_renderWindow->draw(it->second);

            it++;
        }
    }
}
