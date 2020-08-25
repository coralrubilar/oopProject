#pragma once
#include "Command.h"
class SolveCommand :public Command {
public:
	SolveCommand(View* view, Model* model) :Command(view, model) {};
	~SolveCommand() {};
	virtual void doCommand(std::vector<std::string> tokens);
};


