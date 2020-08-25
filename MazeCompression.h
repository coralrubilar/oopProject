#pragma once
#include <fstream>
#include <string>
#include <vector>
#include "Maze2d.h"
class MazeCompression {
public:
	MazeCompression() {};
	MazeCompression(std::vector<MultiTypes*> data = {}, std::string path = "") {
		if (path == "")
			throw "have not path";
		m_path = path;
		if (data.empty())
			return;
		for (auto& d : data) {
			m_data.push_back(d);
		}
	}
	MazeCompression(const MazeCompression& comp) {
		if (comp.m_path == "")
			throw "have not path";
		if (comp.m_data.empty())
			return;
		for (auto& d : comp.m_data) {
			m_data.push_back(d);
		}
		m_path = comp.m_path;
	}


	
	void compress() { 
		if (m_data.empty()) {
			throw "have not data";
		}
		std::ofstream outfile; outfile.open(m_path, std::ios::out | std::ios::binary);
		if (!outfile.is_open()) return;

		int rows = *((int*)m_data[0]->get());
		outfile.write((char*)&rows, sizeof(int));

		int cols = *((int*)m_data[1]->get());
		outfile.write((char*)&cols, sizeof(int));

		std::string* namepointer = static_cast<std::string*>(m_data[2]->get());
		std::string name = *namepointer;

		int lenght = name.length();
		outfile.write((char*)&lenght, sizeof(int));
		outfile.write((char*)name.c_str(), lenght);

		for (auto& i : { 3, 5 }) {
			int x = *((int*)m_data[i]->get());
			int y = *((int*)m_data[i+1]->get());
			outfile.write((char*)&x, sizeof(int));
			outfile.write((char*)&y, sizeof(int));
		}
		char prev = -1;
		int counter = 1;
		for (int i = 7; i < m_data.size(); i++) {
			char tmp = *((char*)m_data[i]->get());
			if (prev != tmp || m_data.size() - 1 == i) {
				if (prev != -1) {
					if (m_data.size() - 1 == i)
						counter++;
					outfile.write((char*)&counter, sizeof(int));
					outfile.write((char*)&prev, sizeof(char));
				}
				counter = 1;
			}
			else counter++;
			prev = tmp;
		}
		outfile.close();
	}




	auto dicompress() { 
		std::ifstream infile; infile.open(m_path, std::ios::in |std::ios::binary);
		if (!infile.is_open())
			throw "Error: cannot open file or the path does't correct";
		int rows,cols;

		infile.read((char*)&rows, sizeof(int));
		m_data.push_back(new INT(rows));

		infile.read((char*)&cols, sizeof(int));
		m_data.push_back(new INT(cols));

		int length;
		infile.read((char*)&length, sizeof(int));
		std::string nameMaze; nameMaze.resize(length);
		infile.read((char*)&nameMaze[0], length);
		

		m_data.push_back(new STRING(nameMaze));


		Position start, goal;
		for (auto& i : { 1,2 }) {
			int x, y;
			infile.read((char*)&x, sizeof(int));
			infile.read((char*)&y, sizeof(int));
			m_data.push_back(new INT(x));
			m_data.push_back(new INT(y));
		}
		while (!infile.eof()) {
			int sizeType; char type;
			infile.read((char*)&sizeType, sizeof(int));
			infile.read((char*)&type, sizeof(char));

			for (int i = 0; i < sizeType; i++) {
				m_data.push_back(new CHAR(type));
			};
		}
		infile.close();
		
		return m_data;
	}
	~MazeCompression() {};

private:
	std::vector<MultiTypes*> m_data;
	std::string m_path;
};