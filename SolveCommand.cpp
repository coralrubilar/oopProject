#include "SolveCommand.h"

void SolveCommand::doCommand(std::vector<std::string> tokens)
{

	/*solve the wanted maze with : a-star or bfs and save the solution*/
	if (tokens.size() != 3)
		return;
	m_model->solve(tokens[1], tokens[2]);
}
