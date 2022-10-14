#include "Scene/SceneManager.hpp"

fr::SceneManager::SceneManager()
{
}

fr::SceneManager::~SceneManager()
{
	removeAll();
}

bool fr::SceneManager::add(std::unique_ptr<fr::IScene> scene)
{
	if (m_scenes.count(scene->getID()))
	{
		return false;
	}

	m_scenes[scene->getID()] = std::move(scene);
	return true;
}

bool fr::SceneManager::replace(std::unique_ptr<fr::IScene> scene)
{
	unfocusAll();
	add(std::move(scene));
	return true;
}


void fr::SceneManager::update(const float& delta_time)
{
	if (m_scenes.empty())
	{
		return;
	}

	for (auto it = m_scenes.cbegin(), next_it = it; it != m_scenes.cend(); it = next_it)
	{
		++next_it;
		if (it->second->getState() == SceneState::MarkedForRemoval)
		{
			m_scenes.erase(it);
		}
		else if (it->second->getState() == SceneState::Focused)
		{
			if (it->second->getFlags().can_handle_events)
				it->second->handleEvents();
			if (it->second->getFlags().can_handle_input)
				it->second->handleInput();
			if (it->second->getFlags().can_update)
				it->second->update(delta_time);
			if (it->second->getFlags().can_handle_events)
				it->second->handleEvents();
		}

	}
}

void fr::SceneManager::draw()
{
	if (m_scenes.empty())
	{
		return;
	}

	for (auto it = m_scenes.cbegin(), next_it = it; it != m_scenes.cend(); it = next_it)
	{
		++next_it;
		if (it->second->getState() == SceneState::MarkedForRemoval)
		{
			m_scenes.erase(it);
		}
		else if (it->second->getState() == SceneState::Focused)
		{
			if (it->second->getFlags().can_draw)
				it->second->draw();
		}

	}
}

void fr::SceneManager::remove(const std::string& scene_id)
{
	if (!m_scenes.empty() && m_scenes.count(scene_id) && m_scenes[scene_id]->getState() != SceneState::MarkedForRemoval)
	{
		m_scenes[scene_id]->setState(SceneState::MarkedForRemoval);
	}
}

void fr::SceneManager::removeAll()
{
	if (m_scenes.empty())
	{
		return;
	}

	for (const auto& it : m_scenes)
	{
		if (it.second->getState() != SceneState::MarkedForRemoval)
		{
			it.second->setState(SceneState::MarkedForRemoval);
		}
	}
}

void fr::SceneManager::removeAllFocused()
{
	if (m_scenes.empty())
	{
		return;
	}

	for (const auto& it : m_scenes)
	{
		if (it.second->getState() != SceneState::MarkedForRemoval && it.second->getState() == SceneState::Focused)
		{
			it.second->setState(SceneState::MarkedForRemoval);
		}
	}
}

void fr::SceneManager::removeAllUnfocused()
{
	if (m_scenes.empty())
	{
		return;
	}

	for (const auto& it : m_scenes)
	{
		if (it.second->getState() != SceneState::MarkedForRemoval && it.second->getState() == SceneState::Unfocused)
		{
			it.second->setState(SceneState::MarkedForRemoval);
		}
	}
}

void fr::SceneManager::unfocusAll()
{
	if (m_scenes.empty())
	{
		return;
	}

	for (const auto& it : m_scenes)
	{
		if (it.second->getState() != SceneState::MarkedForRemoval)
		{
			it.second->setState(SceneState::Unfocused);
		}
	}
}

void fr::SceneManager::focusAll()
{
	if (m_scenes.empty())
	{
		return;
	}

	for (const auto& it : m_scenes)
	{
		if (it.second->getState() != SceneState::MarkedForRemoval)
		{
			it.second->setState(SceneState::Focused);
		}
	}
}

void fr::SceneManager::changeState(const std::string& scene_id, const fr::SceneState state)
{
	if (m_scenes.empty() || !m_scenes.count(scene_id))
	{
		return;
	}

	if (m_scenes[scene_id]->getState() == SceneState::MarkedForRemoval)
	{
		return;
	}

	m_scenes[scene_id]->setState(state);
}

void fr::SceneManager::changeFlag(const std::string& scene_id, const fr::SceneFlags flags)
{
	if (m_scenes.empty() || !m_scenes.count(scene_id))
	{
		return;
	}

	if (m_scenes[scene_id]->getState() == SceneState::MarkedForRemoval)
	{
		return;
	}

	m_scenes[scene_id]->setFlags(flags);
}

const std::shared_ptr<fr::IScene> fr::SceneManager::get(const std::string& scene_id)
{
	if (!m_scenes.empty())
	{
		return nullptr;
	}

	if (m_scenes.count(scene_id))
	{
		if (m_scenes[scene_id]->getState() == SceneState::MarkedForRemoval)
		{
			return nullptr;
		}

		std::shared_ptr<fr::IScene> shared_scene = std::move(m_scenes[scene_id]);
		return shared_scene;
	}

	return nullptr;
}