/*
	Name:
	IState

	Description:
	An interface used for creating app states. Inherit from it and implement virtual functions.

	Used by:
	StateManager
*/

#pragma once
#include <iostream>

#include "StateManager.hpp"


namespace fr
{
	class StateManager;
	class IState
	{
	public:
		IState(){}
		virtual ~IState() {}

		void setName(const std::string& name)
		{
			m_stateName = name;
		}

		const std::string& getName()
		{
			return m_stateName;
		}

		virtual void handleEvents() = 0;
		virtual void handleInput() = 0;
		virtual void update(const float& deltaTime) = 0;
		virtual void draw() = 0;
	private:
		std::string m_stateName = "Default";
	};
}