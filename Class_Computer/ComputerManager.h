#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "Computer.h"
#include "InputData.h"

class ComputerManager
{
	public:
		//CPU - Motherboard compatibility
		static bool areCPUAndMotherboardCompatible(const Computer& pc);

		//RAM - Motherboard compatibility
		static bool areRAMAndMotherboardCompatible(const Computer& pc);

		//Power Supply check
		static bool isPowerSupplyPowerful(const Computer& pc);

		//Computer power check
		static bool isComputerPowerful(const Computer& pc);

		//Read data from file
		static Computer readFileData(const std::vector<std::string> data);

		//Write data in file
		static std::vector<std::string> writeFileData(const Computer& pc);

		//Info of components
		static std::string getCPUInfo(const Computer& pc);
		static std::string getGPUInfo(const Computer& pc);
		static std::string getRAMInfo(const Computer& pc);
		static std::string getStorageInfo(const Computer& pc);
		static std::string getPowerSupplyInfo(const Computer& pc);
		static std::string getMotherboardInfo(const Computer& pc);
};

