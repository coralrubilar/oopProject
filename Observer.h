#pragma once
#include <string>
class Observable;
class Observer {
public:
	virtual void update(const std::string  msg) = 0;
};