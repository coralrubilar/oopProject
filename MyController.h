#pragma once
#include "Controller.h"
#include "MyModel.h"
#include "MyView.h"
#include "DirPathCommand.h"
#include "GenerateMazeCommand.h"
#include "DisplayCommand.h"
#include "SaveMazeCommand.h"
#include "LoadMazeCommand.h"
#include "MazeSizeCommand.h"
#include "FileSizeCommand.h"
#include "SolveCommand.h"
#include "DisplaySolutionCommand.h"
class MyController : public Controller {
public:
	MyController(View* view, Model* model);


	// Inherited via Controller
	virtual Command* get(const std::string& command);
	virtual void update(const std::string msg);
};