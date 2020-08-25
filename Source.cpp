#include "SimpleMaze2dGenerator.h"
#include "MyMaze2dGenerator.h"
#include "Maze2dGeneratorA.h"
#include "MazeCompression.h"
#include "Maze2d.h"
#include "Maze2dState.h"
#include "Maze2dSearchable.h"
#include "BFS.h"
#include "AStar.h"
#include "Demo.h"
#include "CLI.h"


/*
class TestMazeGenerator
{
public:
	TestMazeGenerator() {};
	void testMazeGenerator(Maze2dGenerator* mg) {

		std::cout << "Time = " << mg->measureAlgorithmTime("Simple", 7) << std::endl;

		std::unique_ptr<Maze2d> maze = mg->generate("Simple", 7);

		Position p = maze->getStartPosition();
		std::cout << "Position Start= " << p << std::endl;

		std::cout << "Possible move in start = " << std::endl;
		std::vector<std::string> ps = maze->getPossibleMove(p);
		for (std::string x : ps) {
			std::cout << x << " ";
		}
		std::cout << std::endl;

		p = maze->getGoalPosition();
		std::cout << "Position Goal = " << p << std::endl;
		//cout << maze << endl;

		std::cout << "Print the maze = " << std::endl;
		maze->print();
		std::cout << std::endl;
		std::unique_ptr<State<Position>> sd = std::unique_ptr<Maze2dState>(new Maze2dState(maze->getStartPosition()));
		std::unique_ptr<State<Position>> ed = std::unique_ptr<Maze2dState>(new Maze2dState(maze->getGoalPosition()));

		
		if (sd == ed) {
			std::cout << "yes" << std::endl;
		}
		else {
			std::cout << "No" << std::endl;

		}

		std::unique_ptr<Searchable<Position>> searchable = std::unique_ptr<Maze2dSearchable>(new Maze2dSearchable(maze));
		std::cout << searchable->getStartState().getState() << std::endl;
		std::cout << searchable->getGoalState().getState() << std::endl;
		std::vector<State<Position>> possibleStates = searchable->getAllPossibleStates(searchable->getStartState());

		for (int i = 0; i < (int)possibleStates.size(); i++) {
			std::cout << possibleStates[i].getState() << std::endl;
		}
		std::unique_ptr<Searcher<Position>> bfs = std::unique_ptr<BFS<Position>>(new BFS<Position>());
		auto s = bfs->search(searchable);
		std::unique_ptr<Searcher<Position>> astarM = std::unique_ptr<AStar<Position>>(new AStar<Position>("M"));
		Solution<Position> aM = astarM->search(searchable);
		std::unique_ptr<Searcher<Position>> astarA = std::unique_ptr<AStar<Position>>(new AStar<Position>("A"));
		Solution<Position> aA = astarA->search(searchable);

		if (s == aM && aM == aA) {
			std::cout << "Equals" << std::endl;
		}
	}
};
*/
int main() {
	CLI c(std::cin, std::cout);
	c.start();
	//SimpleMaze2dGenerator mazegen;
	//std::unique_ptr<Maze2d> maze = std::move(mazegen.generate("test",13,15));
	//maze->print();
	//auto data = maze->getData();
	//MazeCompression c(data, "test.data");
	//c.compress();
	//MazeCompression c1({}, "test.data");
	//auto data2 = c1.dicompress();
	//Maze2d maze1(data);
	//Maze2d maze2(data2);
	//maze1.print(); std::cout << std::endl;
	//maze2.print(); std::cout << std::endl;
	//if (maze2 == maze1) {
	//	std::cout << "Equls" << std::endl;
	//}//  בפרוקט אחד שואל אותי אם ישלך בין זוג
	//std::cin.get();
	//return 0;
	//Demo d;
	//d.run();
	//std::cin.get();
	//return 0;
	//TestMazeGenerator t1;
	//t1.testMazeGenerator(new SimpleMaze2dGenerator());// בנינו את המבוך
	//std::cin.get();
	return 0;

}