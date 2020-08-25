#include "MyController.h"

Command* MyController::get(const std::string& command)
{
	auto it = m_commands.find(command);
	if (it == m_commands.end())
		return nullptr;
	return (it->second);
}

MyController::MyController(View* view,Model* model):Controller(view, model) {

		m_commands["dir"] = new DirPathCommand(view, model);
		m_commands["generate maze"] = new GenerateMazeCommand(view, model);
		m_commands["display"] =new DisplayCommand(view, model);
		m_commands["save maze"] = new SaveMazeCommand(view, model);
		m_commands["load maze"] = new LoadMazeCommand(view, model);
		m_commands["maze size"] = new MazeSizeCommand(view, model);
		m_commands["file size"] = new FileSizeCommand(view, model);
		m_commands["solve"] = new SolveCommand(view, model);
		m_commands["display solution"] =new DisplaySolutionCommand(view, model);

}

void MyController::update(const std::string msg) {
	m_view->print(msg);
}