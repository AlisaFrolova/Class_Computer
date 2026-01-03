#pragma once

#include <string>

struct CPUInputData
{
	std::string model;
	int cores;
	int frequency; //MHz
	std::string socket;
};

struct GPUInputData
{
	std::string model;
	int memorySize; //GB
	int powerConsumption; //Watts
};

struct RAMInputData
{
	int capacity; //GB
	std::string type;
	int frequency; //MHz
};

struct StorageInputData
{
	int capacity; //GB
	std::string type;
	int readSpeed; //MB/s
};

struct PowerSupplyInputData
{
	int wattage;
	std::string certificate;
};

struct MotherboardInputData
{
	std::string model;
	std::string chipset;
	std::string formFactor;
	std::string socket;
	std::string typeOfRAM;
};