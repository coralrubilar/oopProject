#include "MazeSizeCommand.h"

void MazeSizeCommand::doCommand(std::vector<std::string> tokens)
{
	m_model->sizeMaze(tokens[2]);
}
