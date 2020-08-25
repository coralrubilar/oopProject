#pragma once
#include "Command.h"
class GenerateMazeCommand :public Command {
public:
	GenerateMazeCommand(View* view, Model* model) :Command(view, model) {};
	~GenerateMazeCommand() {};
	virtual void doCommand(std::vector<std::string> tokens);
};

