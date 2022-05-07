/*
	Warning! This is a bleeding edge stuff! It's relatively untested and unfinished and the are probably some bugs.

	Quick note:
	Currently, there's an animation manager under the development, which will, in similar fashion to other managers, create, manage and store the animations.
	Using it as is, is uneficient.
*/

/*
	Name:
	Animation

	Description:
	A single animation.

	Used by:
	AnimationManager
*/

#pragma once
#include "TextureAtlas.hpp"

namespace fr
{
	enum class AnimationState
	{
		Unfocused = 0,
		Paused,
		Playing,
		MarkedForRemoval,
	};
}


namespace fr_util
{

	class Animation : public sf::Drawable
	{
	public:
		Animation()
		{

		}

		Animation(sf::Sprite& sprite, fr::TextureAtlas& textureAtlas)
			:	m_sprite(&sprite), m_textureAtlas(&textureAtlas)
		{
			
		}


		~Animation(){}

		void init(const float& oneCycleDuration, const bool& repeat, const uint64_t& startingFrame, const uint64_t& endingFrame)
		{
			m_cycleDuration = oneCycleDuration;
			m_switchTime = (endingFrame - startingFrame) / m_cycleDuration;
			m_repeat = repeat;
			m_startingFrame = startingFrame;
			m_endingFrame = endingFrame;

			m_currentFrame = m_startingFrame;

			m_initialized = true;
			m_playable = true;
			m_animationState = fr::AnimationState::Paused;
		}

		// for responsiveness, this should be always called before the start of the animation cycle
		const bool applyTextureToSprite()
		{
			if (!m_initialized)
			{
				fr::Log::printDebug(fr::LogColor::Red, true, "Animation: applyTextureToSprite -> The animation was not initialized properly. Make sure that 'init' function was called");
				return false;
			}

			m_sprite->setTexture(m_textureAtlas->getTexture());
			m_sprite->setTextureRect(m_textureAtlas->getFrameTextureRect(m_startingFrame));
			m_currentFrame++;
			return true;
		}

		void play(const float deltaTime)
		{
			if (!m_initialized)
			{
				fr::Log::printDebug(fr::LogColor::Red, true, "Animation: play -> The animation was not initialized properly. Make sure that 'init' function was called");
				return;
			}


			if (m_playable && m_animationState == fr::AnimationState::Playing)
			{
				m_elapsedTime += deltaTime;
				
				if (m_elapsedTime >= m_switchTime)
				{
					if (m_playedOnce && !m_repeat)
					{
						m_sprite->setTextureRect(m_textureAtlas->getFrameTextureRect(m_startingFrame));
						m_playable = false;
						m_animationState = fr::AnimationState::MarkedForRemoval;
					}

					m_animationState = fr::AnimationState::Playing;

					m_totalTime += deltaTime;
					m_elapsedTime -= m_switchTime;

					m_sprite->setTextureRect(m_textureAtlas->getFrameTextureRect(m_currentFrame));
					m_currentFrame++;


					if (m_currentFrame > m_endingFrame)
					{
						m_currentFrame = m_startingFrame;
						m_playedOnce = true;
					}
				}
			}
		}

		void draw(sf::RenderTarget& target, sf::RenderStates states) const override
		{
			target.draw(*m_sprite);
		}

		const fr::AnimationState getAnimationState()
		{
			return m_animationState;
		}

		void setAnimationState(fr::AnimationState state)
		{
			m_animationState = state;
		}

	private:
		fr::AnimationState m_animationState = fr::AnimationState::Unfocused;

		bool m_initialized = false;

		sf::Sprite* m_sprite = nullptr;
		fr::TextureAtlas* m_textureAtlas = nullptr;

		float m_cycleDuration = 0.f;
		float m_totalTime = 0.f;
		float m_switchTime = 0.f;
		float m_elapsedTime = 0.f;

		bool m_repeat = false;
		uint64_t m_currentFrame = 1;
		uint64_t m_startingFrame = 1;
		uint64_t m_endingFrame = 1;

		bool m_playedOnce = false;
		bool m_playable = false;
	};
}