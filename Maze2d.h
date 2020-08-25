#pragma once
#include "Position.h"
#include "Cell.h"




class Maze2d {
protected:
#pragma region Fields
	std::string m_name;
	Position m_start, m_end;
	std::vector<std::vector<Cell>> m_board;
	int m_rows, m_cols;
#pragma endregion
public:
#pragma region Constructor&Distructor
	Maze2d(const std::string& name = "test", int rows = 11, int cols = 11);
	Maze2d(std::vector<MultiTypes*> data);
	virtual ~Maze2d() {}

#pragma endregion
#pragma region GetsFunction
	
	int getRows() const { return m_rows; }
	int getCols() const { return m_cols; }
	std::vector<std::vector<Cell>> getBoard() const { return m_board; }
	Position getStartPosition() const { return m_start; }
	Position getGoalPosition() const { return m_end; }
	std::string getName() const { return m_name; }
	std::vector<std::string> getPossibleMove(Position& p) const;
	std::vector<MultiTypes*> getData();
	

#pragma endregion
#pragma region SetsFunction
	void setStartPosition(int x = 1, int y = 1) {
		setStartPosition(Position(x, y));
	}
	void setStartPosition(const Position& p) {
		m_start = p;
	}

	void setGoalPosition(int x, int y) {
		setGoalPosition(Position(x, y));
	};
	void setGoalPosition(const Position& p) {
		m_end = p;
	}

	void setBoard(const std::vector<std::vector<Cell>>& board) {
		m_board = board;
	}

#pragma endregion
#pragma region AnotherFunction
	void print();
	virtual Position randomPosition();
#pragma endregion
#pragma region Operators
	bool operator==(const Maze2d m);
	friend std::ostream& operator<<(std::ostream& out, Maze2d maze2d);
#pragma endregion
};

