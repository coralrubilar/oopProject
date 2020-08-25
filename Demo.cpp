#include "Demo.h"




/*run myMaze2dGenerator and solve it with:
bfs and a-star Manhatten and a-star Air-Distance and show all the diffrance*/
void Demo::run() {
	SimpleMaze2dGenerator mazegen;
	std::unique_ptr<Maze2d> maze = std::move(mazegen.generate("test", 21));
	maze->print();
	std::unique_ptr<Searchable<Position>> searchable = std::unique_ptr<Maze2dSearchable>(new Maze2dSearchable(maze));
	std::unique_ptr<Searcher<Position>> bfs = std::unique_ptr<BFS<Position>>(new BFS<Position>());
	auto s = bfs->search(searchable);// solution
	std::unique_ptr<Searcher<Position>> astarM = std::unique_ptr<AStar<Position>>(new AStar<Position>("M"));
	auto aM = astarM->search(searchable);
	std::unique_ptr<Searcher<Position>> astarA = std::unique_ptr<AStar<Position>>(new AStar<Position>("A"));
	auto aA = astarA->search(searchable);
	std::cout << std::endl;
	std::cout << "BFS solution: " << s.getSize() << std::endl;
	std::cout << "Astar Manhatten solution: " << aM.getSize() << std::endl;
	std::cout << "Astar Air-Distance solurion: " << aA.getSize() << std::endl;
	std::cout << std::endl;
	std::cout << "BFS Develop: " << s.getCounterDevelop() << std::endl;
	std::cout << "Astar Manhatten Develop: " << aM.getCounterDevelop() << std::endl;
	std::cout << "Astar Air-Distance Develop: " << aA.getCounterDevelop() << std::endl;
	std::cout << std::endl;
	std::cout << "BFS path: "; s.print(); std::cout << std::endl;
	std::cout << "Astar Manhatten path: "; s.print(); std::cout << std::endl;
	std::cout << "Astar Air-Distance path: "; s.print(); std::cout << std::endl;

	return;
}