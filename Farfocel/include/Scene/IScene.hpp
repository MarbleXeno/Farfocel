#pragma once
#include "SceneManager.hpp"
#include <memory>

namespace fr
{
	class SceneManager;

	enum class SceneState
	{
		// Tell the scene manager to stop updating and drawing the state
		Unfocused = 0,
		// ... to start updating and drawing
		Focused,
		// ... to remove the state
		MarkedForRemoval
	};

	// Scenes can have multiple flags.
	// They only apply to focused screens and have no effect for unfocused ones
	struct SceneFlags
	{
		SceneFlags(const bool _can_handle_events, const bool _can_handle_input, const bool _can_update, const bool _can_draw)
			: can_handle_events(_can_handle_events), can_handle_input(_can_handle_input), can_update(_can_update), can_draw(_can_draw)
		{
			
		}
		~SceneFlags() {}

		bool can_handle_events;
		bool can_handle_input;
		bool can_update;
		bool can_draw;
	};

	class IScene
	{
	public:
		IScene(const std::string& id)
			: m_screen_state(SceneState::Focused), m_screen_id(id), m_screen_flags(true, true, true, true)
		{

		}

		virtual ~IScene()
		{
			
		}

		virtual void handleEvents() = 0;
		virtual void handleInput() = 0;
		virtual void update(const float& delta_time) = 0;
		virtual void draw() = 0;

		const std::string& getID() { return m_screen_id; }
		const SceneFlags& getFlags() { return m_screen_flags; }
		const SceneState& getState() { return  m_screen_state; }

		const void setFlags(const SceneFlags& flags) { m_screen_flags = flags; }
		const void setState(const SceneState& state) { m_screen_state = state; }

	protected:

	private:
		SceneState m_screen_state;
		SceneFlags m_screen_flags;

		std::string m_screen_id;
	};
}
