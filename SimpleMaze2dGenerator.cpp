#include "SimpleMaze2dGenerator.h"

using namespace std;

std::unique_ptr<Maze2d> SimpleMaze2dGenerator::generate(const std::string& name, int rows) {

		std::unique_ptr<Maze2d> newMaze = std::unique_ptr<Maze2d>(new Maze2d(name, rows, rows));
		std::vector<std::vector<Cell>> mazeboard = newMaze->getBoard();


		srand((unsigned)time(NULL));				        			// Pick random start cell
		int random = 0;
		int randomX = ((2 * rand()) + 1) % (rows - 1);				// Generate a random odd number between 1 and m_size
		int randomY = ((2 * rand()) + 1) % (rows - 1);				// Generate a random odd number between 1 and m_size
		newMaze->setStartPosition(randomY, randomX);
		Position entry = newMaze->getStartPosition();

		int visitedCells = 1;
		int totalCells = ((rows - 1) / 2) * ((rows - 1) / 2);
		int percent = 0;

		mazeboard[randomY][randomX].display = 'S';						// Set S as the start cell
		mazeboard[randomY][randomX].visited = true;						// Set start cell as visited;

		randomX = ((2 * rand()) + 1) % (rows - 1);
		randomY = ((2 * rand()) + 1) % (rows - 1);

		newMaze->setGoalPosition(randomY, randomX);
		Position end = newMaze->getGoalPosition();
		if (end == entry) {
			int endx = end.getX();
			if (endx < rows - 2) { endx++; }
			else if (endx == rows - 1) { endx--; }
			randomX = endx;
			newMaze->setGoalPosition(randomY, randomX);
		}
		mazeboard[end.getX()][end.getY()].display = 'E';

		Position temp = entry;


		int diff_x = temp.getX() - end.getX();
		int diff_y = temp.getY() - end.getY();

		double removeWalls = (totalCells * 0.9); //a caclculation to remove walls  

		int temp_x = temp.getX();
		int temp_y = temp.getY();

		if (diff_x < 0) {
			diff_x++;
		}
		else if (diff_x > 0) {
			diff_x--;
		}
		else if (diff_y < 0) {
			diff_y++;
		}
		else if (diff_y > 0) {
			diff_y--;
		}



		while (diff_x != 0 || diff_y != 0)
		{

			if (diff_x == 0) {
				random = 2;
			}
			else if (diff_y == 0) {
				random = 1;
			}
			else {
				random = (rand() % 2) + 1;
			}

			/*up or down - Y */


			if ((random == 1) && (diff_x < 0)) {  //UP
				diff_x++;
				temp_x++;
				temp.setX(temp_x);
				mazeboard[temp_x][temp_y].visited = true;		// Mark cell moved to as visited
				mazeboard[temp_x][temp_y].display = '0';		// Update path
				mazeboard[temp_x][temp_y].top_wall = false;	// Knock down wall
			}
			else if ((random == 1) && (diff_x > 0)) {  //DOWN 
				diff_x--;
				temp_x--;
				temp.setX(temp_x);
				mazeboard[temp_x][temp_y].visited = true;		// Mark cell moved to as visited
				mazeboard[temp_x][temp_y].display = '0';		// Update path
				mazeboard[temp_x][temp_y].bot_wall = false;	// Knock down wall
			}

			else if ((random == 2) && (diff_y < 0)) {  // LEFT
				diff_y++;
				temp_y++;
				temp.setY(temp_y);
				mazeboard[temp_x][temp_y].visited = true;		// Mark cell moved to as visited
				mazeboard[temp_x][temp_y].display = '0';		// Update path
				mazeboard[temp_x][temp_y].left_wall = false;	// Knock down wall
			}
			else if ((random == 2) && (diff_y > 0)) {  //RIGTH
				diff_y--;
				temp_y--;
				temp.setY(temp_y);
				mazeboard[temp_x][temp_y].visited = true;		// Mark cell moved to as visited
				mazeboard[temp_x][temp_y].display = '0';		// Update path
				mazeboard[temp_x][temp_y].right_wall = false;	// Knock down wall
			}
		}
		for (int i = 0; i < removeWalls; i++)
		{
			random = 0;
			randomX = ((2 * rand()) + 1) % (rows - 1);
			randomY = ((2 * rand()) + 1) % (rows - 1);
			if (mazeboard[randomX][randomY].display == '1')
			{
				mazeboard[randomX][randomY].display = '0';
				mazeboard[randomX][randomY].visited = true;
			}
		}
		newMaze->setBoard(mazeboard);

		return newMaze;

}