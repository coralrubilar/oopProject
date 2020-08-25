#pragma once
#include "Command.h"
class DisplayCommand :public Command {
public:
	DisplayCommand(View* view, Model* model) :Command(view, model) {};
	~DisplayCommand() {};
	virtual void doCommand(std::vector<std::string> tokens);
};

