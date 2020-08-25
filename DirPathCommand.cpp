#include "DirPathCommand.h"
void DirPathCommand::doCommand(std::vector<std::string> tokens)
{
	auto& path = tokens[1]; //path to folder

	for(auto& p: fs::directory_iterator(path))
		m_view->print(p.path().string());
}
