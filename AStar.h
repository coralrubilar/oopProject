#pragma once
#include "CommonSearcher.h"
#include <map>
#include <iostream>
#include <string>

#define INFINITE 32000

template <class T>
class AStar : public CommonSearcher<T>
{
public:
	AStar(const std::string& type) : h(type) {};
	~AStar() {};
public:

	typedef double (*function_pointer)(const State<T>&, const State<T>&);
	double distance_Manhattan( State<T>& from, State<T>& to) {
		
		return from - to;
	}

	double airline_distance(State<T>& from, State<T>& to) {
		return from.difference_between_State(to);
	}
	virtual Solution<T> search(std::unique_ptr<Searchable<T>>& s)
	{
		int counter = 0;
		Solution<T> solution;
		auto& start = s->getStartState();
		auto& goal = s->getGoalState();
		std::vector<State<T>> close;
		g_score[start] = 0;
		CommonSearcher<T>::m_openList.push(start);
		if (h == "M") 
			f_score[start] = g_score[start] + distance_Manhattan(start, goal);
		else f_score[start] = g_score[start] + airline_distance(start, goal);
		while (!CommonSearcher<T>::m_openList.empty()) {
			counter++;
			State<T> n(CommonSearcher<T>::popOpenList());
			std::vector<State<T>>open;
			auto queue = CommonSearcher<T>::m_openList;
			auto b = queue.empty();
			while (!queue.empty()) {
				open.push_back(queue.top());
				queue.pop();
			}
			if (n == goal)
			{
				State<T> tmp = n;
				while (tmp != start) {
					solution.addSolution(tmp);
					tmp = *(tmp.getCameFrom());
				}
				solution.setCounter(counter);
				break;
			}
			CommonSearcher<T>::m_openList.pop();
			close.push_back(n);
			auto moves = s->getAllPossibleStates(n);
			for (auto move : moves) {
				const auto& inopen = std::find(open.begin(), open.end(), move) != open.end();
				const auto& inclose = std::find(close.begin(), close.end(), move) != close.end();
				auto tentative_g_score = g_score[n] + distance_Manhattan(n, move);
				if(!inopen)
					g_score[move] = INFINITE;
				if (tentative_g_score < g_score[move]) {
					if(((move.getCameFrom() != nullptr) && *(move.getCameFrom()) != n) || move.getCameFrom() == nullptr)
						move.setCameFrom(n); 
					g_score[move] = tentative_g_score;
					if (h == "M")
						f_score[move] = g_score[move] + distance_Manhattan(move, goal);
					else f_score[move] = g_score[move] + airline_distance(move, goal);
					if (!inopen && !inclose)
						CommonSearcher<T>::m_openList.push(move);
				}
			}
		}
		return solution;
	};

private:
	std::string h;
	std::map<State<T>, double> g_score;
	std::map<State<T>, double> f_score;
};