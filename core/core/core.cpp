#include <include.hpp>

Core::Core()
{
	g_Logger.Info("Core::Core()");
}

Core::~Core()
{
	g_Logger.Info("Core::~Core()");
}

void Core::Tick()
{
	g_Logger.Info("Core::Tick()");
	
	Cache::Tick();
	Aimbot::Tick();
	ESP::Tick();
}
