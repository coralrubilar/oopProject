#pragma once
#include <map>
#include "Model.h"
#include "Solution.h"
#include "BFS.h"
#include "AStar.h"
#include "Maze2dSearchable.h"
class MyModel :public Model {
private:
	std::map<std::string, std::unique_ptr<Maze2d>> m_mazes;
	std::map<std::string, std::unique_ptr<Solution<Position>>> m_solutionMazes;
public:
	MyModel():Model(){}
	~MyModel(){}
	virtual void generator(const std::string name, int rows);
	virtual Maze2d* display(const std::string name);
	virtual void saveMaze(const std::string name, const std::string path);
	virtual void loadMaze(const std::string name, const std::string path);
	virtual void sizeMaze(const std::string name);
	virtual void sizeFile(const std::string name);
	virtual void solve(const std::string name, const std::string alg);
	virtual void displaySolution(const std::string name);
	virtual std::vector<std::string> names() {
		std::vector<std::string> tmp;
		for (auto& name : m_mazes)
			tmp.push_back(name.first);
		return tmp;
	};
};