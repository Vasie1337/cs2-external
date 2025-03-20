#pragma once
#include "../include.hpp"

class Core : public Logger, Cache, public Aimbot, public ESP
{
public:
	Core();
	~Core();
	bool Tick();
private:
};

