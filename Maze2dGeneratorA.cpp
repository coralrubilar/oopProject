#include "Maze2dGeneratorA.h"

std::string Maze2dGeneratorA::measureAlgorithmTime(const std::string& name, int rows)
{
	const clock_t begin_time = clock();
	generate(name, rows);
	int resualt = clock() - begin_time;
	return std::to_string(resualt);
}
