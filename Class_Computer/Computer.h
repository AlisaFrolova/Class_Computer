#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "CPU.h"
#include "GPU.h"
#include "RAM.h"
#include "Storage.h"
#include "PowerSupply.h"
#include "Motherboard.h"

using namespace std;

class Computer
{
private:
	string type;
	CPU cpu;
	GPU gpu;
	vector <RAM> ramModules;
	Storage storage;
	PowerSupply power_supply;
	Motherboard motherboard;

	bool hasCPU;
	bool hasGPU;
	bool hasStorage;
	bool hasPowerSupply;
	bool hasMotherboard;
public:
	//constructor
	Computer();

	//setters
	void setType(const string& new_t);
	void setCPU(const CPU& new_c);
	void setGPU(const GPU& new_g);
	void setStorage(const Storage& new_s);
	void setPowerSupply(const PowerSupply& new_ps);
	void setMotherboard(const Motherboard& new_m);

	//getters
	const string& getType()const;
	const CPU& getCPU()const;
	const GPU& getGPU()const;
	const Storage& getStorage()const;
	const PowerSupply& getPowerSupply()const;
	const Motherboard& getMotherboard()const;

	//RAM-work
	bool addRAM(RAM new_module);
};