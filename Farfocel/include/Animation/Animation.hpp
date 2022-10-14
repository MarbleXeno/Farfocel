#pragma once
#include "Resource/TextureAtlas.hpp"

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


namespace fru
{

	class Animation : public sf::Drawable
	{
	public:
		Animation()
		{

		}

		Animation(sf::Sprite& sprite, fr::TextureAtlas& texture_atlas)
			: m_sprite(&sprite), m_texture_atlas(&texture_atlas)
		{

		}


		~Animation() {}

		void init(const float& one_cycle_duration, const bool& repeat, const uint64_t& starting_frame, const uint64_t& ending_frame)
		{
			m_cycle_duration = one_cycle_duration;
			m_switch_time = (ending_frame - starting_frame) / m_cycle_duration;
			m_repeat = repeat;
			m_starting_frame = starting_frame;
			m_ending_frame = ending_frame;

			m_current_frame = m_starting_frame;

			m_initialized = true;
			m_playable = true;
			m_animation_state = fr::AnimationState::Paused;
		}

		void changeSwitchTime(const float& switch_time)
		{
			m_switch_time = switch_time;
		}

		// for responsiveness, this should be always called before the start of the animation cycle
		const bool applyTextureToSprite()
		{
			if (!m_initialized)
			{
				return false;
			}

			m_sprite->setTexture(m_texture_atlas->getTexture());
			m_sprite->setTextureRect(m_texture_atlas->getFrameTextureRect(m_starting_frame));
			m_current_frame++;
			return true;
		}

		void play(const float deltaTime)
		{
			if (!m_initialized)
			{
				return;
			}

			if (m_playable)
			{
				m_elapsedTime += deltaTime;

				if (m_elapsedTime >= m_switch_time)
				{
					m_totalTime += deltaTime;
					m_elapsedTime -= m_switch_time;

					if (m_playedOnce && !m_repeat)
					{
						m_sprite->setTextureRect(m_texture_atlas->getFrameTextureRect(m_starting_frame));
						m_playable = false;
						m_animation_state = fr::AnimationState::MarkedForRemoval;
					}

					if (m_animation_state == fr::AnimationState::Playing)
					{
						m_sprite->setTextureRect(m_texture_atlas->getFrameTextureRect(m_current_frame));
						m_current_frame++;
					}


					if (m_current_frame > m_ending_frame)
					{
						m_current_frame = m_starting_frame;
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
			return m_animation_state;
		}

		void setAnimationState(fr::AnimationState state)
		{
			if (state == fr::AnimationState::Paused)
				m_elapsedTime = 0;

			m_animation_state = state;
		}

	private:
		fr::AnimationState m_animation_state = fr::AnimationState::Unfocused;

		bool m_initialized = false;

		sf::Sprite* m_sprite = nullptr;
		fr::TextureAtlas* m_texture_atlas = nullptr;

		float m_cycle_duration = 0.f;
		float m_totalTime = 0.f;
		float m_switch_time = 0.f;
		float m_elapsedTime = 0.f;

		bool m_repeat = false;
		uint64_t m_current_frame = 1;
		uint64_t m_starting_frame = 1;
		uint64_t m_ending_frame = 1;

		bool m_playedOnce = false;
		bool m_playable = false;
	};
}