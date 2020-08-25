#pragma once

#include <string>
#include <iostream>
#include <filesystem>
#include "Command.h"

namespace fs = std::filesystem;
class DirPathCommand:public Command {
public:
	DirPathCommand(View* view, Model* model) :Command(view,model){};
	~DirPathCommand() {};
	virtual void doCommand(std::vector<std::string> tokens);
};