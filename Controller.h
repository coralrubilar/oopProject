#pragma once
#include "Maze2d.h"
#include "Command.h"
#include <map>
#include "Observable.h"
#include "View.h"
#include "Model.h"
class Controller :public Observer {
public:
	Controller(View* view, Model* model) {
		m_view = view;
		m_model = model;
	}
	
	~Controller() {};
public:
	virtual Command* get(const std::string& command) = 0;

protected:
	View* m_view;
	Model* m_model;
	std::map<std::string, Command*> m_commands; // hash-map

};