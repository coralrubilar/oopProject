#include "Position.h"

#pragma region Constructor
Position::Position(int x, int y) : m_x(x), m_y(y) {}
Position::Position(const Position& p) { *this = p; }
Position::~Position() {};
#pragma endregion
#pragma region Operators
std::ostream& operator <<(std::ostream & os, const Position & p) {
	os << "{" << p.m_x << ", " << p.m_y << "}";
	return os;
}
Position& Position::operator=(const Position & p) {
	this->m_x = p.m_x;
	this->m_y = p.m_y;
	return *this;
}

bool Position::operator==(const Position & p) {
	return (m_x == p.m_x && m_y == p.m_y);
}
double Position::operator-(const Position & p) {
	double totalX = abs(m_x - p.m_x);
	double totalY = abs(m_y - p.m_y);
	return totalX + totalY;
}
#pragma endregion
#pragma region AnotherFunctions

double Position::difference(const Position & p) {
	return sqrt(pow(m_x - p.m_x, 2) + pow(m_y - p.m_y, 2));
}


#pragma endregion