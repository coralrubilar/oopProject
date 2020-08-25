#pragma once
#include <iostream>
#include <vector>
#include "State.h"
#include "Maze2d.h"
template <class T>
class Solution
{
public:
	Solution(): m_counterDevelopments(0) {};
	Solution(const Solution& s) {
		for (auto& x : s.m_solution)
		{
			m_solution.push_back(x);
		}
		this->m_counterDevelopments = s.m_counterDevelopments;
	}
	~Solution() {};
public:
	std::vector<State<T>> getSolution() const { return m_solution; }
	void addSolution(const State<T>& s) { m_solution.push_back(s); }
	void setCounter(const int counter) { m_counterDevelopments = counter; }

	int getSize() { return m_solution.size(); }
	int getCounterDevelop() const { return m_counterDevelopments; }
	
	void print() {
		int size = m_solution.size();
		for (auto& it : m_solution) {
			size--;
			if (size)
				std::cout << it.getState() << "->";
			else std::cout << it.getState() << std::endl ;
		}

	}
public:
	bool operator== (const Solution& solution) {
		if (m_solution.size() != solution.m_solution.size())
			return false;
		for (int i = 0; i < (int)m_solution.size(); i++)
			if (m_solution[i] != solution.m_solution[i])
				return false;
		return true;
	}
	friend std::ostream& operator<< ( std::ostream& out,  Solution& s)
	{
		int size = s.getSolution().size();
		for (auto& it : s.getSolution()) {
			size--;
			if (size)
				out << it.getState() << "<-";
			else out << it.getState() << std::endl;
		}
		return out;
	}
private:
	std::vector<State<T>> m_solution; 
	int m_counterDevelopments = 0;
};

