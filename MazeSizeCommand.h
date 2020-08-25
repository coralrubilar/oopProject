#pragma once
#include "Command.h"
class MazeSizeCommand :public Command {
public:
	MazeSizeCommand(View* view, Model* model) :Command(view, model) {};
	~MazeSizeCommand() {};
	virtual void doCommand(std::vector<std::string> tokens);
};
