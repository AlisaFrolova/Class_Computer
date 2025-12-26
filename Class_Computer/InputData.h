#pragma once

#include <string>

using namespace std;

const int MIN_VALUE = 1;
const int MAX_VALUE = 10000;

struct CPUInputData
{
	string model;
	int cores;
	int frequency;
	string socket;
};
struct GPUInputData
{
	string model;
	int memorySize; //GB
	int powerConsumption; //Watts
};
struct RAMInputData
{
	int capacity; //GB
	string type;
	int frequency; //MHz
};
struct StorageInputData
{
	int capacity; //GB
	string type;
	int readSpeed; //MB/s
};
struct PowerSupplyInputData
{
	int wattage;
	string certificate;
};
struct MotherboardInputData
{
	string model;
	string chipset;
	string formFactor;
	string socket;
	string typeOfRAM;
};