#pragma once
#include "Searcher.h"
#include <queue>

template < class T>
class CommonSearcher : public Searcher<T>
{
public:
	CommonSearcher(): m_evaluatedNodes(0){}
	virtual ~CommonSearcher() {};

public:
	virtual Solution<T> search(std::unique_ptr<Searchable<T>>& s) = 0;
	virtual int getNumberOfNodesEvaluated() { return m_evaluatedNodes; };


public:
	const State<T>& popOpenList() {
		m_evaluatedNodes++;
		return m_openList.top();
	}

protected:
	int m_evaluatedNodes;
	std::priority_queue<State<T>, std::vector<State<T>>, std::greater<State<T>>> m_openList;// שדה אצל האבא של ASTAR
};

