#include "SaveMazeCommand.h"
#include "MazeCompression.h"
void SaveMazeCommand::doCommand(std::vector<std::string> tokens)
{
	/*save maze in file*/
	m_model->saveMaze(tokens[2], tokens[3]);
}
