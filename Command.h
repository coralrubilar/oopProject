#pragma once
#include <string>
#include "View.h"
#include "Model.h"

class Command
{
protected:
	View* m_view;
	Model* m_model;
public:
	Command(View* view,Model* model) : m_view(view), m_model(model) {};
	Command(const Command& c) : m_view(c.m_view), m_model(c.m_model) {}
	virtual ~Command() { delete m_view; delete m_model; };
	virtual void doCommand(std::vector<std::string> tokens) = 0;
};