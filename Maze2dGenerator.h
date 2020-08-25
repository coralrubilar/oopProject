#pragma once
#include "Maze2d.h"
class Maze2dGenerator
{
public:
	virtual std::unique_ptr<Maze2d> generate(const std::string& name, int rows) = 0;
	virtual std::string measureAlgorithmTime(const std::string& name, int rows) = 0;

};