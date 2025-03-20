#pragma once
#include <include.hpp>

class Core : private Cache, private Aimbot, private ESP
{
public:
	Core();
	~Core();
	void Tick();
private:
};

