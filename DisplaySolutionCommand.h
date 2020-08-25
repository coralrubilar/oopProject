#pragma once
#include "Command.h"
class DisplaySolutionCommand :public Command {
public:
	DisplaySolutionCommand(View* view, Model* model) :Command(view, model) {};
	~DisplaySolutionCommand() {};
	virtual void doCommand(std::vector<std::string> tokens);
};