#pragma once
#include <include.hpp>

class Data
{
public:
	// Constants
	static constexpr int MAX_ENTITIES = 1024;
	static constexpr int MAX_PLAYERS = 64;

	// Slow Tick
	std::uintptr_t client_dll;
	std::uintptr_t local_player;
	std::uintptr_t entity_list;
	std::uintptr_t global_vars;

	std::uint32_t local_team;
	std::vector<std::uintptr_t> list_entries;

	// Fast Tick
	std::vector<Entity> entities;
	std::vector<Player> players;
};

