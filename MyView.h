#pragma once
#include "View.h"

class MyView : public View {
public:
	MyView() {};
	~MyView() {};
	virtual void print(std::string str) {
		std::cout << str << std::endl;
	}
	virtual std::string input() {
		std::string s;
		std::getline(std::cin, s);
		return s;
	}
};