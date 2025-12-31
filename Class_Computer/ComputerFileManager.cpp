#include "ComputerFileManager.h"

void ComputerFileManager::writeFile(const vector <string>& data)
{
	ofstream fout(FILE_NAME, ios::out);
	for (int i = 0; i < data.size(); i++)
	{
		fout << data.at(i) << endl;
	}
}

vector <string> ComputerFileManager::readFile()
{
	ifstream fin(FILE_NAME, ios::in);
	vector <string> data;
	if (fin.is_open())
	{
		string line;
		while (getline(fin, line))
		{
			data.push_back(line);
		}
	}
	fin.close();

	return data;
}