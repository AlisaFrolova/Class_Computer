#pragma once

#include <string>
#include <fstream>
#include <vector>

const std::string FILE_NAME = "ComputerData.txt";

class ComputerFileManager
{
public:
	static void writeFile(const std::vector <std::string>& data);
	static std::vector <std::string> readFile();
};

