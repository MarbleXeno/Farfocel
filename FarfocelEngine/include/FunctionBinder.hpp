/*
    Name:
    FunctionBinder

    Description:
    Stores a custom function as a variable that then can be executed.

    Used by:
    InputManager,
    EventManager
*/

#pragma once
#include <iostream>
#include <functional>

#include "Log.hpp"

namespace fr_util
{
    enum class FunctionBinderState
    {
        NotExecuted = 0,
        Executed,
        MarkedForRemoval
    };

    class FunctionBinder
    {
        public:
            FunctionBinder()
            {
                m_function = [](){fr::Log::printDebug(fr::LogColor::White, true, "Function Binding: constructor -> No function hasn't been binded yet."); };
                m_state = FunctionBinderState::NotExecuted;
                m_repeat = false;
            }

            ~FunctionBinder() {}
            

            void bindFunction(std::function<void()> function, bool hasToRepeat)   
            {   
                m_function = function;  
                m_repeat = hasToRepeat;    
            }

            bool execFunction()
            {
                m_function();
                m_state = FunctionBinderState::Executed;
                return true;
            }
            
            void changeState(const FunctionBinderState state)
            {
                m_state = state;
            }

            const FunctionBinderState getState()
            {
                return m_state;
            }

            bool hasToRepeat()  {   return m_repeat;    }
        private:
            std::function<void()> m_function;

            FunctionBinderState m_state;

            //a logic to not repeat the function should be done on the wrapper's side
            bool m_repeat;


    };
}