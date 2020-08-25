#include "GenerateMazeCommand.h"
void GenerateMazeCommand::doCommand(std::vector<std::string> tokens)
{
	/*in our project the Columns and rows are equals*/
	int rows, cols;
	rows = std::stoi(tokens[3]);
	m_model->generator(tokens[2], rows);

}