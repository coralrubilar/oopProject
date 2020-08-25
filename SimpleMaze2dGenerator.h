#pragma once
#include "Maze2dGeneratorA.h"
class SimpleMaze2dGenerator: public Maze2dGeneratorA
{
public:
	virtual std::unique_ptr<Maze2d> generate(const std::string& name, int rows);
};

