#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <filesystem>
#include <sstream> 

namespace fs = std::filesystem;

std::vector<std::string> tokensString(std::string line)
{

	std::vector<std::string> tokens;
	std::stringstream check(line);
	std::string intermediate;
	while (std::getline(check, intermediate, ' '))
		tokens.push_back(intermediate);
	return tokens;
}

