#pragma once

#include "MultiTypes.h"
#include <iostream>
#include <fstream>
#include <sstream> 
#include <vector>
#include <string>
#include <ctime>
#include <algorithm>
#include <cstdio>
#include <stack>
#include <list>
class Position {
public:
#pragma region Constructor
	Position(int x = 0, int y = 0);
	Position(const Position& p);
	~Position();
#pragma endregion
#pragma region Gets&Sets
	int getX() const { return m_x; }
	int getY() const { return m_y; }
	//bool getVisited() const { return m_visited; }

	void setX(int x) { m_x = x; }
	void setY(int y) { m_y = y; }
	//void setVisited(bool v) { m_visited = v; }
#pragma endregion
#pragma region Operators
	friend std::ostream& operator <<(std::ostream& os, const Position& p);
	Position& operator=(const Position& p);
	bool operator==(const Position& p);
	double operator-(const Position& p);
#pragma endregion
#pragma region AnotherFunctions

	double difference(const Position& p);


#pragma endregion
private:
#pragma region Fields
	int m_x, m_y;
#pragma endregion
};