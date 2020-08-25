#pragma once
#include "Command.h"
class FileSizeCommand :public Command {
public:
	FileSizeCommand(View* view, Model* model) :Command(view, model) {};
	~FileSizeCommand() {};
	virtual void doCommand(std::vector<std::string> tokens);
};
