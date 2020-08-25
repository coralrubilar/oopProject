#pragma once
#include "State.h"



class Maze2dState : public State<Position>
{
public:
	Maze2dState():State<Position>() {}
	Maze2dState(Position state) : State<Position>(state) {};
	~Maze2dState() {};
};
