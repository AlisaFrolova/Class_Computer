#include "ComputerManager.h"

//CPU - Motherboard compatibility
bool ComputerManager::areCPUAndMotherboardCompatible(const Computer& pc, std::string& error_message)
{
	if (pc.isCPUInstalled() && pc.isMotherboardInstalled())
	{
		if (pc.getCPU().getSocket() == pc.getMotherboard().getSocket()) return true;
		else
			error_message = "CPU and Motherboard are not compatible!";
	}
	else
		error_message = "CPU or/and Motherboard is not installed!";
	return false;
}

//RAM - Motherboard compatibility
bool ComputerManager::areRAMAndMotherboardCompatible(const Computer& pc, std::string& error_message)
{
	if (pc.isRAMInstalled() && pc.isMotherboardInstalled())
	{
		for (int i = 0; i < pc.getRAM().size(); i++)
		{
			int max_ram_size = 0;
			int pos = (pc.getMotherboard().getTypeOfRAM().find('x'));
			if (pos != std::string::npos) max_ram_size = std::stoi(pc.getMotherboard().getTypeOfRAM().substr(0, pos));
			else
			{
				error_message = "Invalid type of RAM for Motherboard!";
				return false;
			}
			if (pc.getRAM().size() > max_ram_size)
			{
				error_message = "Number of RAM modules is greater than the number of slots for RAM on the Motherboard!";
				return false;
			}
			if (pc.getMotherboard().getTypeOfRAM().find(pc.getRAM().at(i).getType()) == std::string::npos)
			{
				error_message = "Type of RAM modules differs from the type of RAM on the Motherboard!";
				return false;
			}
		}
		return true;
	}
	else
	{
		error_message = "RAM or/and Motherboard is not installed!";
		return false;
	}
}

//Power Supply check
bool ComputerManager::isPowerSupplyPowerful(const Computer& pc, std::string& error_message)
{
	if (pc.isBuildReady())
	{
		int wattage_sum;
		int cpu_wattage = pc.getCPU().getCoresNumber() * 0.002 * pc.getCPU().getFrequency();
		int ram_wattage = pc.getRAM().size() * 3;
		wattage_sum = cpu_wattage + pc.getGPU().getPowerConsumption() + ram_wattage + 5 + 30;
		if (wattage_sum > pc.getPowerSupply().getWattage())
		{
			error_message = "Power Supply is not powerful enough for current build!";
			return false;
		}
		else
			return true;
	}
	else
	{
		error_message = "Build is not completed!";
		return false;
	}
}

//Computer power check
bool ComputerManager::isComputerPowerful(const Computer& pc, std::string& error_message)
{
	if (pc.isBuildReady())
	{
		int power_points = 0;

		//CPU-check
		if (pc.getCPU().getCoresNumber() >= 8) power_points++;
		if (pc.getCPU().getFrequency() >= 4000) power_points++;

		//GPU-check
		if (pc.getGPU().getMemorySize() >= 10) power_points++;

		//RAM-check
		if (pc.getRAM().size() >= 4) power_points++;
		int ram_sum = 0;
		for (int i = 0; i < pc.getRAM().size(); i++)
		{
			ram_sum += pc.getRAM().at(i).getCapacity();
			if (pc.getRAM().at(i).getType() == "DDR4" || pc.getRAM().at(i).getType() == "DDR5") power_points++;
		}
		if (ram_sum >= 16) power_points++;

		//Storage-check
		if (pc.getStorage().getCapacity() >= 500) power_points++;
		if (pc.getStorage().getReadSpeed() >= 100) power_points++;

		//PowerSupply-check
		if (pc.getPowerSupply().getWattage() >= 750) power_points++;
		if (pc.getPowerSupply().getCertificate() == "Gold" || pc.getPowerSupply().getCertificate() == "Platinum" || pc.getPowerSupply().getCertificate() == "Titanium") power_points++;

		//Motherboard-check
		if (pc.getMotherboard().getChipset() == "Z" || pc.getMotherboard().getChipset() == "B" || pc.getMotherboard().getChipset() == "X") power_points++;
		if (pc.getMotherboard().getFormFactor() == "ATX") power_points++;

		if (power_points >= 10) return true;
		else
		{
			error_message = "Build is not very powerful!";
			return false;
		}
	}
	else
	{
		error_message = "Build is not completed!";
		return false;
	}
}

//Read data from file
Computer ComputerManager::readFileData(const std::vector<std::string> data)
{
	Computer pc;
	CPU cpu; GPU gpu; Storage storage; PowerSupply ps; Motherboard mb;

	for (int i = 0; i < data.size(); i++)
	{
		size_t posType = data.at(i).find(':');
		std::string type = data.at(i).substr(0, posType);//component type
		std::string type_data = data.at(i).substr(posType + 1); //the whole data about the component

		if (type == "CPU info")
		{
			CPUInputData temp_cpu;
			size_t posField = type_data.find(" | ");
			temp_cpu.model = type_data.substr(0, posField);
			type_data = type_data.substr(posField + 3); // " | " = 3 symbols
			cpu.setModel(temp_cpu.model);

			posField = type_data.find(" | ");
			temp_cpu.cores = stoi(type_data.substr(0, posField));
			type_data = type_data.substr(posField + 3);
			cpu.setCoresNumber(temp_cpu.cores);

			posField = type_data.find(" | ");
			temp_cpu.frequency = stoi(type_data.substr(0, posField));
			type_data = type_data.substr(posField + 3);
			cpu.setFrequency(temp_cpu.frequency);

			temp_cpu.socket = type_data; //the last one
			cpu.setSocket(temp_cpu.socket);

			pc.setCPU(cpu); 
		}
		if (type == "GPU info")
		{
			GPUInputData temp_gpu;
			size_t posField = type_data.find(" | ");
			temp_gpu.model = type_data.substr(0, posField);
			type_data = type_data.substr(posField + 3);
			gpu.setModel(temp_gpu.model);

			posField = type_data.find(" | ");
			temp_gpu.memorySize = stoi(type_data.substr(0, posField));
			type_data = type_data.substr(posField + 3);
			gpu.setMemorySize(temp_gpu.memorySize);

			temp_gpu.powerConsumption = stoi(type_data);
			gpu.setPowerConsumption(temp_gpu.powerConsumption);

			pc.setGPU(gpu); 
		}
		if (type == "Number of Modules")
		{
			size_t posType2 = data.at(i).find(':', posType + 1);
			int numModules = stoi(data.at(i).substr(posType + 1, posType2 - posType - 1));
			type_data = data.at(i).substr(posType2 + 1);

			for (int j = 0; j < numModules; j++)
			{
				RAMInputData module;

				size_t posField = type_data.find(" | ");
				module.capacity = stoi(type_data.substr(0, posField));
				type_data = type_data.substr(posField + 3);

				posField = type_data.find(" | ");
				module.type = type_data.substr(0, posField);
				type_data = type_data.substr(posField + 3);

				posField = type_data.find("; ");
				module.frequency = stoi(type_data.substr(0, posField));
				type_data = type_data.substr(posField + 2);

				RAM ramModule(module.capacity, module.type, module.frequency);
				pc.addRAM(ramModule); 
			}
		}
		if (type == "Storage info")
		{
			StorageInputData temp_st;
			size_t posField = type_data.find(" | ");
			temp_st.capacity = stoi(type_data.substr(0, posField));
			type_data = type_data.substr(posField + 3);
			storage.setCapacity(temp_st.capacity);

			posField = type_data.find(" | ");
			temp_st.type = type_data.substr(0, posField);
			type_data = type_data.substr(posField + 3);
			storage.setType(temp_st.type);

			temp_st.readSpeed = stoi(type_data);
			storage.setReadSpeed(temp_st.readSpeed);

			pc.setStorage(storage); 
		}
		if (type == "Power Supply info")
		{
			PowerSupplyInputData temp_ps;
			size_t posField = type_data.find(" | ");
			temp_ps.wattage = stoi(type_data.substr(0, posField));
			type_data = type_data.substr(posField + 3);
			ps.setWattage(temp_ps.wattage);

			temp_ps.certificate = type_data;
			ps.setCertificate(temp_ps.certificate);

			pc.setPowerSupply(ps);
		}
		if (type == "Motherboard info")
		{
			MotherboardInputData temp_mb;
			size_t posField = type_data.find(" | ");
			temp_mb.model = type_data.substr(0, posField);
			type_data = type_data.substr(posField + 3);
			mb.setModel(temp_mb.model);

			posField = type_data.find(" | ");
			temp_mb.chipset = type_data.substr(0, posField);
			type_data = type_data.substr(posField + 3);
			mb.setChipset(temp_mb.chipset);

			posField = type_data.find(" | ");
			temp_mb.formFactor = type_data.substr(0, posField);
			type_data = type_data.substr(posField + 3);
			mb.setFormFactor(temp_mb.formFactor);

			posField = type_data.find(" | ");
			temp_mb.socket = type_data.substr(0, posField);
			type_data = type_data.substr(posField + 3);
			mb.setSocket(temp_mb.socket);

			temp_mb.typeOfRAM = type_data;
			mb.setTypeOfRAM(temp_mb.typeOfRAM);
			pc.setMotherboard(mb); 
		}
	}

	return pc;
}

//Write data in file
std::vector<std::string> ComputerManager::writeFileData(const Computer& pc)
{
		std::vector <std::string> data;

		data.push_back(getCPUInfo(pc));
		data.push_back(getGPUInfo(pc));
		data.push_back(getRAMInfo(pc));
		data.push_back(getStorageInfo(pc));
		data.push_back(getPowerSupplyInfo(pc));
		data.push_back(getMotherboardInfo(pc));

		return data;
}

//Info
std::string ComputerManager::getCPUInfo(const Computer& pc)
{
	if (pc.isCPUInstalled())
	{
		std::string CPU_data = "CPU info: " + pc.getCPU().getModel() + " | " + std::to_string(pc.getCPU().getCoresNumber()) + " | " + std::to_string(pc.getCPU().getFrequency()) + " | " + pc.getCPU().getSocket();
		return CPU_data;
	}
	else
		return "CPU is not installed!";
}

std::string ComputerManager::getGPUInfo(const Computer& pc)
{
	if (pc.isGPUInstalled())
	{
		std::string GPU_data = "GPU info: " + pc.getGPU().getModel() + " | " + std::to_string(pc.getGPU().getMemorySize()) + " | " + std::to_string(pc.getGPU().getPowerConsumption());
		return GPU_data;
	}
	else
		return "GPU is not installed!";
}

std::string ComputerManager::getRAMInfo(const Computer& pc)
{
	std::string RAM_data;
	if (pc.isRAMInstalled())
	{
		RAM_data = "Number of Modules: " + std::to_string(pc.getRAM().size()) + ": ";
		for (int i = 0; i < pc.getRAM().size(); i++)
		{
			RAM_data = RAM_data + std::to_string(pc.getRAM().at(i).getCapacity()) + " | " + pc.getRAM().at(i).getType() + " | " + std::to_string(pc.getRAM().at(i).getFrequency()) + "; ";
		}
		return RAM_data;
	}
	else
	{
		RAM_data = "RAM is not installed!";
		return RAM_data;
	}
}

std::string ComputerManager::getStorageInfo(const Computer& pc)
{
	if (pc.isStorageInstalled())
	{
		std::string Storage_data = "Storage info: " + std::to_string(pc.getStorage().getCapacity()) + " | " + pc.getStorage().getType() + " | " + std::to_string(pc.getStorage().getReadSpeed());
		return Storage_data;
	}
	else
		return "Storage is not installed!";
}

std::string ComputerManager::getPowerSupplyInfo(const Computer& pc)
{
	if (pc.isPowerSupplyInstalled())
	{
		std::string PowerSupply_data = "Power Supply info: " + std::to_string(pc.getPowerSupply().getWattage()) + " | " + pc.getPowerSupply().getCertificate();
		return PowerSupply_data;
	}
	else
		return "Power Supply is not installed!";
}

std::string ComputerManager::getMotherboardInfo(const Computer& pc)
{
	if (pc.isMotherboardInstalled())
	{
		std::string Motherboard_data = "Motherboard info: " + pc.getMotherboard().getModel() + " | " + pc.getMotherboard().getChipset() + " | " + pc.getMotherboard().getFormFactor() + " | " + pc.getMotherboard().getSocket() + " | " + pc.getMotherboard().getTypeOfRAM();
		return Motherboard_data;
	}
	else
		return "Motherboard is not installed!";
}