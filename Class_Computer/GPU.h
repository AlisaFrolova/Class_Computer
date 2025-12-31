#pragma once

#include <iostream>
#include <string>

class GPU
{
private:
	std::string model;
	int memorySize; //GB
	int powerConsumption; //Watts
public:
	//constructor
	GPU();
	GPU(std::string m, int mS, int pC);

	//setters
	void setModel(const std::string& new_m);
	void setMemorySize(const int& new_ms);
	void setPowerConsumption(const int& new_pc);

	//getters
	const std::string& getModel() const;
	const int& getMemorySize() const;
	const int& getPowerConsumption() const;
};

