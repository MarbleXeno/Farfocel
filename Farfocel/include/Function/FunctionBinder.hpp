#pragma once
#include <iostream>
#include <functional>

namespace fru
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
            m_function = []() {};
            m_state = FunctionBinderState::NotExecuted;
            m_repeat = false;
        }

        ~FunctionBinder() {}


        void bindFunction(std::function<void()> function, bool has_to_repeat)
        {
            m_function = function;
            m_repeat = has_to_repeat;
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

        bool hasToRepeat() { return m_repeat; }
    private:
        std::function<void()> m_function;

        FunctionBinderState m_state;

        bool m_repeat;


    };
}