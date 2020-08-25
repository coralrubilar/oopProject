#pragma once

#include <string>
#include <memory>
#include "Maze2d.h"
template <class T>
class State
{
public:
	State(): m_cost(0), m_cameFrom(nullptr) {}
	State(T state) : m_state(state), m_cost(0), m_cameFrom(nullptr) {}
	State(const State<T>& s){
		*this = s;
	}
	friend bool operator<(const State<T>& left,const State<T>& right) {
		return left.m_cost < right.m_cost;
	}
	friend bool operator>(const State<T>& left, const State<T>& right) {
		return left.m_cost > right.m_cost;
	}
	State<T>& operator=(const State<T>& s) {
		this->m_state = s.m_state;
		this->m_cost = s.m_cost;
		if (s.m_cameFrom != nullptr)
			setCameFrom(*(s.m_cameFrom));
		else m_cameFrom = nullptr;
		return *this;
	}
	virtual ~State() {

	};
public:
	double calculateCost(const State<T>& targetState) {
		State<T> tmp = targetState;
		double	sum = 0;
		while (tmp.m_cameFrom != nullptr) {
			sum++;
			tmp = *(tmp.m_cameFrom);
		}
		return sum;
	}
public:
	bool operator != (const State<T>& s) { return !(m_state == s.m_state); }
	
	bool operator == (const State<T>& s) { return m_state == s.m_state; }
	T& getState() {
		return m_state;
	}
	std::unique_ptr<State<T>>& getCameFrom()  { // return the position of thr father
		return m_cameFrom; 
	}
	//the distance from this state to s state
	double operator-(State<T>& s) { return m_state - s.m_state; }
	double getCost() {
		return m_cost;
	}
	void setCost(const double& cost) { m_cost = cost; }
	void setCameFrom(State<T>& c) {
		std::unique_ptr<State<T>> tmp = std::make_unique<State<T>>(c);
		m_cameFrom.swap(tmp);
	}
	
	double difference_between_State(const State<T>& goal) {
		return m_state.difference(goal.m_state);
	}
protected:
	T					m_state; // current state(Position)
	double				m_cost;	
	std::unique_ptr<State<T>>	m_cameFrom; //from Where the state was discovered
};
