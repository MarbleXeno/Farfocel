/*
    A State manager that manages the states. Super useful if you wanna create some more complex stuff, with menus and stuff.
*/


#pragma once
#include <iostream>
#include <stack>

#include "IState.hpp"

namespace fr
{
    class IState;
    class StateManager
    {
        public:
            StateManager();
            ~StateManager();

            void replace(IState* state);
            void addTop(IState* state);

            void deleteAll();
            void deleteTop();

            IState* getTop();

            void update();
            void draw();
        private:
            std::stack<IState*> m_states;
    };
}