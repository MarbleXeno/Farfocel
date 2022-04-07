/*
    An inferface used by the State Manager.
*/

#pragma once
#include <SFML/Graphics.hpp>

#include "StateManager.hpp"

namespace fr
{
    class StateManager;
    class IState
    {
        public:
            IState(){}
            virtual ~IState(){}

            void setStateName(const std::string& name){m_stateName = name;}
            const std::string& getStateName(){return m_stateName;}

            virtual void update() = 0;
            virtual void draw() = 0;

        private:
            std::string m_stateName;
    };
}
