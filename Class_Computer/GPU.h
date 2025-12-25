#pragma once

#include <iostream>
#include <string>

using namespace std;

class GPU
{
private:
	string model;
	int memorySize; //GB
	int powerConsumption; //Watts
public:
	//constructor
	GPU(string m, int mS, int pC);

	//setters
	void setModel(const string& new_m);
	void setMemorySize(const int& new_ms);
	void setPowerConsumption(const int& new_pc);

	//getters
	const string& getModel() const;			
	const int& getMemorySize() const;
	const int& getPowerConsumption() const;
};

