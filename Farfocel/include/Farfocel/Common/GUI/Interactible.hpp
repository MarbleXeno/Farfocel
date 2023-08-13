#pragma once

namespace frgu{
    enum class InteractibleState{
        NEUTRAL = 0,
        HIGHLIGHTED = 1,
        ACTIVATED = 2
    };

    class Interactible{
        public:
            Interactible();
            ~Interactible();

            const InteractibleState& GetState() { return mState; }
            void SetState(const InteractibleState& state) { mState = state; }

        protected:
            virtual void OnStateNeutral() = 0;
            virtual void OnStateHighlited() = 0;
            virtual void OnStateActivated() = 0;


        private:
            InteractibleState mState;
    };
}