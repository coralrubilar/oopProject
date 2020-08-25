#include "LoadMazeCommand.h"
#include "MazeCompression.h"
void LoadMazeCommand::doCommand(std::vector<std::string> tokens)
{
	/*load a new maze from file and give it a name*/
	m_model->loadMaze(tokens[3], tokens[2]);
}
