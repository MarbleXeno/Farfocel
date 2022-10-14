#pragma once

// SFML
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
// ---

// ~~~ Farfocel
#include "Scene/SceneManager.hpp"
#include "Function/EventManager.hpp"
#include "Resource/ResourceManager.hpp"
#include "Animation/AnimationManager.hpp"

// Farfocel GUI

// ---

// ~~~


namespace fr
{

	// These structs contain global utilities
	struct FRCLUtils
	{
		FRCLUtils(){}

		FRCLUtils(sf::RenderWindow& render_window, sf::Event& evnt)
			:	event_manager(render_window, evnt), scene_manager(), resource_manager(), animation_manager(render_window)
		{
			
		}

		~FRCLUtils(){}

		fr::EventManager event_manager;
		fr::SceneManager scene_manager;
		fr::ResourceManager resource_manager;
		fr::AnimationManager animation_manager;
	};

	struct SFMLUtils
	{
		SFMLUtils()
			: render_window()
		{

		}
		~SFMLUtils(){}

		sf::RenderWindow render_window;
		
	};
}
// ---