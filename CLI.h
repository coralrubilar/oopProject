#pragma once
#include <iostream>
#include "MyController.h"
#include "getFilesFromPath.h"

/* control our system*/
class CLI {
protected:
	std::istream& m_in;
	std::ostream& m_out;
	Controller* m_controller;
	Model* m_model;
public:
	CLI(std::istream& in, std::ostream& out)
		: m_in(in), m_out(out) {}
	~CLI() {};
public:
	void start() {
		std::string command = "";
			m_model = new MyModel;
			m_controller = new MyController(new MyView,m_model);
			m_model->addObserver(*m_controller);
		while (command.compare("exit")) {
			std::cout << "-> ";
			std::getline(std::cin, command);
			Command* commandClass;
			auto tokens = tokensString(command);
			if(command.compare("exit") == 0 || tokens.size() == 1)
				continue;
			if(tokens[0].compare("dir") == 0 || (tokens[0].compare("display") == 0 && tokens[1].compare("solution") != 0)
				|| tokens[0].compare("solve") == 0)
				commandClass = m_controller->get(tokens[0]);
			else commandClass = m_controller->get(tokens[0]+" "+ tokens[1]);
			if (commandClass != nullptr)
				commandClass->doCommand(tokens);
			else MyView().print("Error: Command does not exist");

		}
		std::vector<std::string> names = m_model->names();
		for (auto& name : names) {
			std::vector<std::string> tokens = { "save","maze" ,name,name + ".data" };
			m_controller->get("save maze")->doCommand(tokens);
		}
	}
};