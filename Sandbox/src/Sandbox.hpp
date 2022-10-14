#pragma once
#include "Core/Farfocel.hpp"
#include "Core/Runtime.hpp"

#include "Scenes/TestScene.hpp"

namespace sb
{
	class Sandbox : public fr::Runtime
	{
	public:
		Sandbox();
		~Sandbox() override;

		void start() override;
		void update(const float& delta_time) override;
		void draw() override;
	private:
	};
}