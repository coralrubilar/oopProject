#pragma once
#include "Command.h"
class SaveMazeCommand :public Command {
public:
	SaveMazeCommand(View* view, Model* model) :Command(view, model) {};
	~SaveMazeCommand() {};
	virtual void doCommand(std::vector<std::string> tokens);
};

