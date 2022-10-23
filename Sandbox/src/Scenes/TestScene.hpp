#pragma once
#include <SFML/Graphics.hpp>

#include "Core/Farfocel.hpp"

namespace sb
{
	class TestScene : public fr::IScene
	{
	public:
		TestScene(const std::string& id, fr::SFMLUtils* sfml_utils, fr::FRCLUtils* fr_utils);
		~TestScene();

		void handleEvents();
		void handleInput();
		void update(const float& delta_time);
		void draw();

	private:
		fr::SFMLUtils& m_sfml;
		fr::FRCLUtils& m_fr;
	};
}
