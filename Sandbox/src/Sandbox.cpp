#include "Sandbox.hpp"

sb::Sandbox::Sandbox()
{
	initWindow();
	initAppLoop();
}

sb::Sandbox::~Sandbox()
{

}

void sb::Sandbox::start()
{
	
	FRCL.scene_manager.add(std::make_unique<sb::TestScene>("Test", &SFML, &FRCL));
}

void sb::Sandbox::update(const float& delta_time)
{
	
}

void sb::Sandbox::draw()
{

}

int main()
{
	sb::Sandbox* app = new sb::Sandbox;
	delete app;
	return 0;
}
