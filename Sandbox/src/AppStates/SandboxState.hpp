#pragma once
#include "Farfocel.hpp"

namespace app
{
	class SandboxState : public fr::IState
	{
	public:
		SandboxState(fr::StateManager& stateManager, sf::RenderWindow& renderWindow);
		~SandboxState();

		void handleEvents();
		void handleInput();
		void update(const float& deltaTime);
		void draw();
	private:
		fr::StateManager* m_stateManager;
		sf::RenderWindow* m_renderWindow;

        fr::ResourceManager m_resourceManager;

		fr_util::Animation m_animation;

		sf::Sprite m_animatedLogoSprite;
	};
}