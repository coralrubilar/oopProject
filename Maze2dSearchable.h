#pragma once
#include "Searchable.h"
#include "Maze2d.h"
#include "Maze2dState.h"
#include <typeinfo>

/*adapter patten*/

class Maze2dSearchable : public Searchable<Position>
{
public:
	Maze2dSearchable(std::unique_ptr<Maze2d>& maze2d);
	~Maze2dSearchable() {};


	virtual State<Position>& getStartState();

	virtual State<Position>& getGoalState();

	virtual std::vector<State<Position>> getAllPossibleStates(State<Position>& s);

private:
	std::unique_ptr<Maze2d> m_Maze2d;
};

