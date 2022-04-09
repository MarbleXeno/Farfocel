/*
    A function binding class. It's used by the Event and Input Managers.
*/

#pragma once
#include <iostream>
#include <functional>


namespace fr_util
{
    class FunctionBinding
    {
        public:
            FunctionBinding()
            {
                m_callbackFunction = [](){std::cout<<"FUCK YOU :D\n";};
                m_hasBeenExecuted = false;
                m_hasToRepeat = false;
            }

            ~FunctionBinding() {}
            
            void bindFunction(std::function<void()> function, bool hasToRepeat)   
            {   
                m_callbackFunction = function;  
                m_hasToRepeat = hasToRepeat;    
            }

            bool execFunction()
            {
                m_callbackFunction();

                m_hasBeenExecuted = true;

                return true;
            }
            
            void changeState(bool state)
            {
                m_hasBeenExecuted = state;
            }

            bool hasToRepeat()  {   return m_hasToRepeat;    }
            bool hasBeenExecuted()  {   return m_hasBeenExecuted;  }
        private:
            std::function<void()> m_callbackFunction;
            bool m_hasBeenExecuted;
            bool m_hasToRepeat;
    };
}