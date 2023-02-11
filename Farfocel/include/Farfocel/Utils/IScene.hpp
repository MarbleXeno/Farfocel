#pragma once
#include <iostream>
#include "Farfocel/Managers/ScenesManager.hpp"
namespace fr {
	class ScenesManager;

	enum class SceneState {
		Unfocused = 0,		// can't be updated or drawn
		Focused,			// can be
		MarkedForRemoval	// remove the scene
	};

	// These flags only apply to focused screens.
	struct SceneFlags {
		SceneFlags(const bool& _canHandleEvents, const bool& _canHandleInput, const bool& _canUpdate, const bool& _canDraw) 
			: canHandleEvents(_canHandleEvents), canHandleInput(canHandleInput), canUpdate(_canUpdate), canDraw(_canDraw)
		{}
		~SceneFlags() {}

		bool canHandleEvents;
		bool canHandleInput;
		bool canUpdate;
		bool canDraw;
	};

	class IScene {
	public:
		IScene(const std::string& id) 
			: sceneID(id), sceneState(SceneState::Focused), sceneFlags(true, true, true, true) {}

		IScene(const std::string& id, const SceneState& state, const SceneFlags& flags)
			: sceneID(id), sceneState(state), sceneFlags(flags) {}

		virtual ~IScene() {}

		virtual void Start() = 0;
		virtual void HandleEvents() = 0;
		virtual void HandleInput() = 0;
		virtual void Update() = 0;
		virtual void Draw() = 0;

		void SetState(const SceneState& state) { sceneState = state; }
		void SetFlags(const SceneFlags& flags) { sceneFlags = flags; }

		const std::string& GetID() { return sceneID; }
		const SceneState& GetState() { return sceneState; }
		const SceneFlags& GetFlags() { return sceneFlags; }

	
	protected:
		std::string sceneID;
		SceneState sceneState;
		SceneFlags sceneFlags;
	};
}