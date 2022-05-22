/*
	Name:
	StateManager

	Description:
	Manages and stores app states. Use it for more complex apps/games.
*/

#pragma once
#include <SFML/Graphics.hpp>
#include <stack>

#include "IState.hpp"
#include "Log.hpp"


namespace fr
{
	class IState;
	class StateManager
	{
	public:
		StateManager();
		~StateManager();

		void add(std::unique_ptr<IState> state);
		void replace(std::unique_ptr<IState> state);

		void pop();
		void popAll();

		const uint32_t getStackSize()
		{
			return m_states.size();
		}

		void stateHandleEvents();
		void stateHandleInput();
		void stateUpdate(const float& deltaTime);
		void stateDraw();
	private:
		std::stack<std::unique_ptr<IState>> m_states;
	};
}