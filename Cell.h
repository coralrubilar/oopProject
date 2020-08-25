#pragma once
struct Cell
{
	Cell() :visited(false), top_wall(true), bot_wall(true), left_wall(true), right_wall(true), display('*') {}
	bool visited;
	bool top_wall;
	bool bot_wall;
	bool left_wall;
	bool right_wall;
	char display;
};