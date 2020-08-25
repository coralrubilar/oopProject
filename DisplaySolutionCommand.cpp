#include "DisplaySolutionCommand.h"

void DisplaySolutionCommand::doCommand(std::vector<std::string> tokens)
{
	/*get the solution for the wanted maze*/
	m_model->displaySolution(tokens[2]);
}
