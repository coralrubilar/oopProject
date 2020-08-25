#include "FileSizeCommand.h"

void FileSizeCommand::doCommand(std::vector<std::string> tokens)
{

	m_model->sizeFile(tokens[2]);
}
