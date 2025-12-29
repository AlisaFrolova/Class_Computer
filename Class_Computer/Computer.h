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
#include "ComputerValidator.h"

using namespace std;

class Computer
{
private:
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
	bool setCPU(const CPU& new_c);
	bool setGPU(const GPU& new_g);
	bool setStorage(const Storage& new_s);
	bool setPowerSupply(const PowerSupply& new_ps);
	bool setMotherboard(const Motherboard& new_m);

	//getters
	const CPU& getCPU()const;
	const GPU& getGPU()const;
	const vector<RAM>& getRAM() const;
	const Storage& getStorage()const;
	const PowerSupply& getPowerSupply()const;
	const Motherboard& getMotherboard()const;

	//RAM-work
	bool addRAM(RAM& new_module);

	//check for existence
	bool isCPUInstalled() const;
	bool isGPUInstalled() const;
	bool isRAMInstalled() const;
	bool isStorageInstalled() const;
	bool isPowerSupplyInstalled() const;
	bool isMotherboardInstalled() const;
};