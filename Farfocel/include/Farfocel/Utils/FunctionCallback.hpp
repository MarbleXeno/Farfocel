#pragma once
#include <functional>
#include <iostream>

namespace fru {
	enum class FunctionCallbackState {
		MarkedForExec = 1,
		Executed = 2,
	};

	class FunctionCallback {
	public:

		FunctionCallback(const bool& repeat, const std::function<void()>& callback)
			: mRepeat(repeat), mState(FunctionCallbackState::MarkedForExec), mCallback(callback)
		{}

		~FunctionCallback(){}

		void SetCallback(const std::function<void()>& callback){
			mCallback = callback;
		}

		void SetRepeat(const bool& repeat){mRepeat = repeat;}
		const bool& GetRepeat() { return mRepeat; }

		void SetState(const FunctionCallbackState& state) { mState = state; }
		const FunctionCallbackState& GetState() { return mState; }

		void Execute() {
			mCallback();
			mState = FunctionCallbackState::Executed;
		}

	private:
		bool mRepeat;
		FunctionCallbackState mState;
		std::function<void()> mCallback;
	};
}
