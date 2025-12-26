#pragma once

#include <vector>
#include <string>

#include "CPU.h"
#include "GPU.h"
#include "RAM.h"
#include "Storage.h"
#include "PowerSupply.h"
#include "Motherboard.h"

using namespace std;

class ComputerValidator
{
public: 
	static const int MIN_NUMBER_OF_MODULES = 1;

	static bool isValidType(const string& type);
	static bool isValidCPU(const CPU& cpu);
	static bool isValidGPU(const GPU& gpu);
	static bool isValidRAMModule(const RAM& module);
	static bool isValidRAM(const vector <RAM>& ramModules);
	static bool isValidStorage(const Storage& storage);
	static bool isValidPowerSupply(const PowerSupply& power_supply);
	static bool isValidMotherboard(const Motherboard& motherboard);
};

