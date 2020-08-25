#pragma once
#include "Observer.h"
#include <vector>

class Observable {
public:
	void addObserver(Observer& observer) {
		m_observers.push_back(&observer);
	}
	void notify(const std::string msg){
		for (auto& it : m_observers) {
			it->update(msg);
		}
	}

private:
	std::vector<Observer*> m_observers;
};