#include "MyModel.h"
#include "SimpleMaze2dGenerator.h"
#include "MazeCompression.h"
#include "MyMaze2dGenerator.h"
void MyModel::generator(const std::string name, int rows)
{
	MyMaze2dGenerator simple;
	m_mazes[name] = simple.generate(name, rows);
	this->notify("maze " + name + " is ready" );
}
Maze2d* MyModel::display(const std::string name) {
	if (this->m_mazes.find(name) != this->m_mazes.end())
		return new Maze2d(*(this->m_mazes[name]));
	return nullptr;
}
void MyModel::saveMaze(const std::string name, const std::string path) {
	Maze2d* maze = display(name);           //using Observer and Observable
	if (maze == nullptr)
	{
		this->notify("Error: Maze with the name: " + name + " does not exist");
		return;
	}
	try {
		MazeCompression(maze->getData(), path).compress();
	}
	catch (const char* e) {
		this->notify((std::string)e);
	}
	delete maze;
}
void MyModel::loadMaze(const std::string name, const std::string path) {
	try {
		this->m_mazes[name] = std::unique_ptr<Maze2d>(new Maze2d(MazeCompression({}, path).dicompress()));
	}
	catch (const char* e) {
		this->notify((std::string)e);
	}
}
void MyModel::sizeMaze(const std::string name) {
	auto maze = *(m_mazes[name]);
	auto nameSizeH = sizeof(maze.getName());
	auto CellSizeH = sizeof(Cell) * maze.getRows() * maze.getCols();
	auto PosistionSizeH = sizeof(Position) *2;
	auto total = nameSizeH + CellSizeH + PosistionSizeH + (sizeof(int) * 2);
	this->notify("size Maze on memory: " + std::to_string(total));
}
void MyModel::sizeFile(const std::string name){
	std::ifstream infile; infile.open(name, std::ios::in | std::ios::binary);
	infile.seekg(0, std::ios::end);
	this->notify("size file maze: "+ std::to_string(infile.tellg())+ " bytes");
	infile.close();
}
void MyModel::solve(const std::string name, const std::string alg) {
	std::unique_ptr<Maze2d> maze = std::unique_ptr<Maze2d>(display(name));
	if (maze == nullptr)
	{
		this->notify("Error: Maze with the name: " + name + " does not exist");
		return;
	}
	Solution<Position> solution;
	std::unique_ptr<Searchable<Position>> searchable = std::unique_ptr<Maze2dSearchable>(new Maze2dSearchable(maze));
	std::unique_ptr<Searcher<Position>> search;
	if (alg == "BFS") {
		search = std::unique_ptr<BFS<Position>>(new BFS<Position>());
		solution = search->search(searchable);
	}
	else if (alg == "AStarM") {
		search = std::unique_ptr<AStar<Position>>(new AStar<Position>("M"));
		solution = search->search(searchable);// solution
	}
	else {
		search = std::unique_ptr<AStar<Position>>(new AStar<Position>("A"));
		solution = search->search(searchable);// solution
	}

	m_solutionMazes[name] = std::make_unique<Solution<Position>>(solution);

}

void MyModel::displaySolution(const std::string name) {

	auto it = m_solutionMazes.find(name);
	if (it == m_solutionMazes.end())
		return;
	std::ostringstream out;
	out << *m_solutionMazes[name];
	this->notify(out.str());
}