#include "Maze2dSearchable.h"
#pragma region Ctor
Maze2dSearchable::Maze2dSearchable(std::unique_ptr<Maze2d>& maze2d) {
	m_Maze2d = std::move(maze2d);
}
#pragma endregion
#pragma region Gets
State<Position>& Maze2dSearchable::getStartState() {
	State<Position>* tmp = new Maze2dState(m_Maze2d->getStartPosition());
	return *tmp;
}

State<Position>& Maze2dSearchable::getGoalState() {
	State<Position>* tmp = new Maze2dState(m_Maze2d->getGoalPosition());
	return *tmp;
}

std::vector<State<Position>> Maze2dSearchable::getAllPossibleStates(State<Position>& s) {
	std::vector<State<Position>> possibleStates;
	Position curr = s.getState();
	int currx = curr.getX();
	int curry = curr.getY();
	std::vector<std::string> moves = m_Maze2d->getPossibleMove(curr);
	for (std::string move : moves) {
		int xtemp = 0, ytemp = 0;
		if (move == "Up") {
			ytemp = curry - 1; xtemp = currx;
		}
		else if (move == "Down") {
			ytemp = curry + 1; xtemp = currx;
		}
		else if (move == "Left") {
			ytemp = curry; xtemp = currx - 1;
		}
		else if (move == "Right") {
			ytemp = curry; xtemp = currx + 1;
		}
		if (move == "Right" || move == "Left" || move == "Down" || move == "Up") {
			Position temp(xtemp, ytemp);
			std::unique_ptr<State<Position>> moveState = std::unique_ptr<Maze2dState>(new Maze2dState(temp));
			possibleStates.push_back(*moveState);
		}
	}
	return possibleStates;
}
#pragma endregion