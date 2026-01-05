#pragma once

#include <string>
#include <vector>

#include "Computer.h"
#include "InputData.h"

class ComputerManager
{
	public:
		//CPU - Motherboard compatibility
		static bool areCPUAndMotherboardCompatible(const Computer& pc, std::string& error_message);

		//RAM - Motherboard compatibility
		static bool areRAMAndMotherboardCompatible(const Computer& pc, std::string& error_message);

		//Power Supply check
		static bool isPowerSupplyPowerful(const Computer& pc, std::string& error_message);

		//Computer power check
		static bool isComputerPowerful(const Computer& pc, std::string& error_message);

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

