#include "DisplayCommand.h"
void DisplayCommand::doCommand(std::vector<std::string> tokens)
{
	//get wanted maze
	Maze2d* maze = m_model -> display(tokens[1]);
	if (maze == nullptr)
	{
		m_view->print("Error: Maze with the name: "+ tokens[1] + " does not exist" );
		return;
	}
	std::ostringstream out;
	out << *maze;

	m_view->print(out.str());

	delete maze;
}