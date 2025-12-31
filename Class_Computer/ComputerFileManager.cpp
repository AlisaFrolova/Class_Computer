#include "ComputerFileManager.h"

void ComputerFileManager::writeFile(const std::vector <std::string>& data)
{
	std::ofstream fout(FILE_NAME, std::ios::out);
	for (int i = 0; i < data.size(); i++)
	{
		fout << data.at(i) << std::endl;
	}
}

std::vector <std::string> ComputerFileManager::readFile()
{
	std::ifstream fin(FILE_NAME, std::ios::in);
	std::vector <std::string> data;
	if (fin.is_open())
	{
		std::string line;
		while (getline(fin, line))
		{
			data.push_back(line);
		}
	}
	fin.close();

	return data;
}