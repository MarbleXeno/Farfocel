#pragma once
#include <map>
#include <iostream>
#include <memory>

#include <SFML/Graphics.hpp>

#include "IScene.hpp"

namespace fr
{

	class IScene;
	enum class SceneState;
	struct SceneFlags;

	class SceneManager
	{
	public:
		SceneManager();
		~SceneManager();

		bool add(std::unique_ptr<fr::IScene>scene);
		bool replace(std::unique_ptr<fr::IScene>scene);

		void update(const float& delta_time);
		void draw();

		void remove(const std::string& scene_id);
		void removeAll();
		void removeAllFocused();
		void removeAllUnfocused();

		void unfocusAll();
		void focusAll();

		void changeState(const std::string& scene_id, const fr::SceneState state);
		void changeFlag(const std::string& scene_id, const fr::SceneFlags flags);

		const std::shared_ptr<fr::IScene> get(const std::string& scene_id);
	private:
		std::map<std::string, std::unique_ptr<fr::IScene>> m_scenes;
	};

}
