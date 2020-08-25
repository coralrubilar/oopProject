#pragma once

#include "CommonSearcher.h"
#include <vector>
#include <algorithm>

template <class T>
class BFS : public CommonSearcher<T>
{
public:
	BFS() {};
	~BFS() {};
public:

	
	virtual Solution<T> search(std::unique_ptr<Searchable<T>>& s)
	{
		int counter = 0;
		Solution<T> solution;
		const auto& start = s->getStartState();
		const auto& goal = s->getGoalState();
		std::vector<State<T>> close;
		CommonSearcher<T>::m_openList.push(start);
		while (!CommonSearcher<T>::m_openList.empty()) {
			counter++;
			State<T> n(CommonSearcher<T>::popOpenList());
			CommonSearcher<T>::m_openList.pop();
			close.push_back(n);
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
			auto moves = s->getAllPossibleStates(n);
			for (auto move : moves) {

				std::vector<State<T>>open;
				auto queue = CommonSearcher<T>::m_openList;
				while (!queue.empty()) {
					open.push_back(queue.top());
					queue.pop();
				}

				if ((!(std::find(close.begin(), close.end(), move) != close.end())) && !(std::find(open.begin(), open.end(), move) != open.end())) {

					if (((move.getCameFrom() != nullptr) && *(move.getCameFrom()) != n) || move.getCameFrom() == nullptr)
						move.setCameFrom(n);
					CommonSearcher<T>::m_openList.push(move);
				}
				else if (!(CommonSearcher<T>::m_openList.empty()) && (s->getStartState().calculateCost(CommonSearcher<T>::popOpenList()) > s->getStartState().calculateCost(n) + 1))// של הקודם
				{
					if (!(std::find(open.begin(), open.end(), move) != open.end()))
						CommonSearcher<T>::m_openList.push(move);
					else close.push_back(move);

				}
			}
		}
		return solution;
	};
};
