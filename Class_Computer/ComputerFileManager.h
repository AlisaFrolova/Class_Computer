#pragma once

#include <string>
#include <fstream>
#include <vector>

using namespace std;

const string FILE_NAME = "ComputerData.txt";

class ComputerFileManager
{
public:
	static void writeFile(const vector <string>& data);
	static vector <string> readFile();
};

