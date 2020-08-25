#pragma once
#include <string>
#include<iostream>

class View {
public:
	View() {}
	View(const View& v) {}
	~View() {}
	virtual void print(std::string str) = 0;
	virtual std::string input() = 0;
};