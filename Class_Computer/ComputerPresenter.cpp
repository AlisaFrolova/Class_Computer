#include "ComputerPresenter.h"

ComputerPresenter::ComputerPresenter(Computer& pc, ConsoleView& view) : pc(pc), view(view){}

void ComputerPresenter::run()
{
	readFileData();
	bool running = true;
	while (running)
	{
		view.showMainMenu();
		int choice = view.getMainMenuChoice();

		switch (choice)
		{
		case 1: changeComputer(); break; 
		case 2: checkCompatibility(); break;
		case 3: checkBuildState(); break; 
		case 4: showComputer(); break; 
		case 5: cleanComputer(); break; 
		case 6: writeFileData(); break; 
		case 0: running = false; break; 
		default: view.showMessage("Incorrect enter."); break;
		}
	}
}

//methods
void ComputerPresenter::changeComputer()
{
	bool editing = true;
	while (editing)
	{
		view.showComputerEditMenu();
		int choice = view.getComputerEditChoice();

		switch (choice)
		{
		case 1:
		{
			CPUInputData data = view.inputCPUData();
			CPU cpu(data.model, data.cores, data.frequency, data.socket);
			if (ComputerValidator::isValidCPU(cpu))
			{
				pc.setCPU(cpu);
				view.showMessage("CPU has been installed!");
			}
			else
				view.showMessage("Incorrect enter!");
			break;
		}
		case 2:
		{
			GPUInputData data1 = view.inputGPUData();
			GPU gpu(data1.model, data1.memorySize, data1.powerConsumption);
			if (ComputerValidator::isValidGPU(gpu))
			{
				pc.setGPU(gpu);
				view.showMessage("GPU has been installed!");
			}
			else
				view.showMessage("Incorrect enter!");
			break;
		}
		case 3:
		{
			RAMInputData data2 = view.inputRAMData();
			RAM ram(data2.capacity, data2.type, data2.frequency);
			if (ComputerValidator::isValidRAMModule(ram))
			{
				pc.addRAM(ram);
				view.showMessage("RAM module has been installed!");
			}
			else
				view.showMessage("Incorrect enter!");
			break;
		}
		case 4:
		{
			if (pc.isRAMInstalled())
			{
				std::vector<std::string> RAMInfo;
				for (int i = 0; i < pc.getRAM().size(); i++)
				{
					RAMInfo.push_back(std::to_string(pc.getRAM().at(i).getCapacity()) + " | " + pc.getRAM().at(i).getType() + " | " + std::to_string(pc.getRAM().at(i).getFrequency()));
				}
				view.showRAMByIndex(RAMInfo);

				size_t index = view.getRAMEditIndex(); 
				if (pc.deleteRAM(index-1)) view.showMessage("RAM module has been deleted!");
				else
					view.showMessage("RAM module has not been deleted!");
			}
			else
			{
				view.showMessage("RAM is not installed!");
			}
			break;
		}
		case 5:
		{
			StorageInputData data3 = view.inputStorageData();
			Storage storage(data3.capacity, data3.type, data3.readSpeed);
			if (ComputerValidator::isValidStorage(storage))
			{
				pc.setStorage(storage);
				view.showMessage("Storage has been installed!");
			}
			else
				view.showMessage("Incorrect enter!");
			break;
		}
		case 6:
		{
			PowerSupplyInputData data4 = view.inputPowerSupplyData();
			PowerSupply power_supply(data4.wattage, data4.certificate);
			if (ComputerValidator::isValidPowerSupply(power_supply))
			{
				pc.setPowerSupply(power_supply);
				view.showMessage("Power supply has been installed!");
			}
			else
				view.showMessage("Incorrect enter!");
			break;
		}
		case 7:
		{
			MotherboardInputData data5 = view.inputMotherboardData();
			Motherboard motherboard(data5.model, data5.chipset, data5.formFactor, data5.socket, data5.typeOfRAM);
			if (ComputerValidator::isValidMotherboard(motherboard))
			{
				pc.setMotherboard(motherboard);
				view.showMessage("Motherboard has been installed!");
			}
			else
				view.showMessage("Incorrect enter!");
			break;
		}
		case 0:
		{
			editing = false;
			break;
		}
		default:
			view.showMessage("Incorrect choice.");
			break;
		}
	}
}
void ComputerPresenter::cleanComputer()
{
	Computer new_pc;
	pc = new_pc;
	view.showMessage("Computer has been cleaned!");
}

void ComputerPresenter::showComputer()
{
	bool showing = true;
	while (showing)
	{
		view.showComputerMenu();
		int choice = view.getComputerMenuChoice();

		switch (choice)
		{
		case 1: 
		{
			view.showComputerComponent(getCPUInfo());
			break;
		}
		case 2:
		{
			view.showComputerComponent(getGPUInfo());
			break;
		}
		case 3: 
		{
			view.showComputerComponent(getRAMInfo());
			break;
		}
		case 4: 
		{
			view.showComputerComponent(getStorageInfo());
			break;
		}
		case 5: 
		{
			view.showComputerComponent(getPowerSupplyInfo());
			break;
		}
		case 6:
		{
			view.showComputerComponent(getMotherboardInfo());
			break;
		}
		case 7:
		{
			view.showComputerComponent(getCPUInfo());
			view.showComputerComponent(getGPUInfo());
			view.showComputerComponent(getRAMInfo());
			view.showComputerComponent(getStorageInfo());
			view.showComputerComponent(getPowerSupplyInfo());
			view.showComputerComponent(getMotherboardInfo());
			break;
		}
		case 0:
		{
			showing = false;
			break;
		}
		default:
		{
			view.showMessage("Incorrect choice.");
			break;
		}
		}
	}
}
std::string ComputerPresenter::getCPUInfo() const
{
	if (pc.isCPUInstalled())
	{
		std::string CPU_data = "CPU info: " + pc.getCPU().getModel() + " | " + std::to_string(pc.getCPU().getCoresNumber()) + " | " + std::to_string(pc.getCPU().getFrequency()) + " | " + pc.getCPU().getSocket();
		return CPU_data;
	}
	else
		return "CPU is not installed!";
}
std::string ComputerPresenter::getGPUInfo() const
{
	if (pc.isGPUInstalled())
	{
		std::string GPU_data = "GPU info: " + pc.getGPU().getModel() + " | " + std::to_string(pc.getGPU().getMemorySize()) + " | " + std::to_string(pc.getGPU().getPowerConsumption());
		return GPU_data;
	}
	else
		return "GPU is not installed!";
}
std::string ComputerPresenter::getRAMInfo() const
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
std::string ComputerPresenter::getStorageInfo() const
{
	if (pc.isStorageInstalled())
	{
		std::string Storage_data = "Storage info: " + std::to_string(pc.getStorage().getCapacity()) + " | " + pc.getStorage().getType() + " | " + std::to_string(pc.getStorage().getReadSpeed());
		return Storage_data;
	}
	else
		return "Storage is not installed!";
}
std::string ComputerPresenter::getPowerSupplyInfo() const
{
	if (pc.isPowerSupplyInstalled())
	{
		std::string PowerSupply_data = "Power Supply info: " + std::to_string(pc.getPowerSupply().getWattage()) + " | " + pc.getPowerSupply().getCertificate();
		return PowerSupply_data;
	}
	else
		return "Power Supply is not installed!";
}
std::string ComputerPresenter::getMotherboardInfo() const
{
	if (pc.isMotherboardInstalled())
	{
		std::string Motherboard_data = "Motherboard info: " + pc.getMotherboard().getModel() + " | " + pc.getMotherboard().getChipset() + " | " + pc.getMotherboard().getFormFactor() + " | " + pc.getMotherboard().getSocket() + " | " + pc.getMotherboard().getTypeOfRAM();
		return Motherboard_data;
	}
	else
		return "Motherboard is not installed!";
}

void ComputerPresenter::checkBuildState()
{
	if (pc.isBuildReady()) view.showMessage("Build is completed!");
	else
		view.showMessage("Build is not completed!");
}

void ComputerPresenter::checkCompatibility()
{
	bool checking = true;
	while (checking)
	{
		view.showCompatibilityMenu();
		int choice = view.getCompatibilityMenuChoice();

		switch (choice)
		{
		case 1:
		{
		//1. CPU-Motherboard check
		if (pc.isCPUInstalled() && pc.isMotherboardInstalled())
		{
			if (pc.getCPU().getSocket() == pc.getMotherboard().getSocket()) view.showMessage("CPU and Motherboard are compatible!");
			else
				view.showMessage("CPU and Motherboard are not compatible!");
		}
		else
			view.showMessage("CPU and/or Motherboard are not installed!");
		break;
		}
		case 2:
		{
		//2. RAM-Motherboard check
		if (pc.isRAMInstalled() && pc.isMotherboardInstalled())
		{
			bool ram_comp = true;
			for (int i = 0; i < pc.getRAM().size(); i++)
			{
				std::string ram_data = std::to_string(pc.getRAM().size()) + "x" + pc.getRAM().at(i).getType();
				if (ram_data != pc.getMotherboard().getTypeOfRAM()) ram_comp = false;
			}
			if (ram_comp) view.showMessage("RAM and Motherboard are compatible!");
			else
				view.showMessage("RAM and Motherboard are not compatible!");
		}
		else
			view.showMessage("RAM and/or Motherboard are not installed");
		break;
		}
		case 3:
		{
			//3. Power Supply check
			if (pc.isPowerSupplyInstalled())
			{
				int wattage_sum;
				int cpu_wattage = pc.getCPU().getCoresNumber() * 0.002 * pc.getCPU().getFrequency();
				int ram_wattage = pc.getRAM().size() * 3;
				wattage_sum = cpu_wattage + pc.getGPU().getPowerConsumption() + ram_wattage + 5 + 30;
				if (wattage_sum > pc.getPowerSupply().getWattage()) view.showMessage("3. Power Supply is not powerful enough for current build!");
				else
					view.showMessage("Power Supply is powerful enough for current build!");
			}
			else
				view.showMessage("Power Supply is not installed!");
			break;
		}
		case 4:
		{
			//4. Computer power check
			if (pc.isBuildReady())
			{
				int power_points = 0;

				//CPU-check
				if (pc.getCPU().getCoresNumber() >= 8) power_points++;
				if (pc.getCPU().getFrequency() >= 45) power_points++;

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
				if (pc.getStorage().getReadSpeed() >= 6000) power_points++;

				//PowerSupply-check
				if (pc.getPowerSupply().getWattage() >= 750) power_points++;
				if (pc.getPowerSupply().getCertificate() == "80+ Gold" || pc.getPowerSupply().getCertificate() == "Platinum" || pc.getPowerSupply().getCertificate() == "Titanium") power_points++;

				//Motherboard-check
				if (pc.getMotherboard().getChipset() == "Z" || pc.getMotherboard().getChipset() == "B" || pc.getMotherboard().getChipset() == "X") power_points++;
				if (pc.getMotherboard().getFormFactor() == "ATX") power_points++;
				
				if (power_points >= 10) view.showMessage("Computer is powerful!");
				else
					view.showMessage("Computer is not very powerful!");
			}
			break;
		}
		case 0:
		{
			checking = false; 
			break;
		}
		default: 
		{
			view.showMessage("Incorrect choice.");
			break;
		}
		}
	}
}

void ComputerPresenter::writeFileData()
{
	if (!pc.isBuildReady()) view.showMessage("Cannot save. Build is not completed!");
	else
	{
		std::vector <std::string> data;
		data.push_back(getCPUInfo());
		data.push_back(getGPUInfo());
		data.push_back(getRAMInfo());
		data.push_back(getStorageInfo());
		data.push_back(getPowerSupplyInfo());
		data.push_back(getMotherboardInfo());

		ComputerFileManager::writeFile(data);

		view.showMessage("Build has been saved!");
	}
}

void ComputerPresenter::readFileData()
{
	std::vector <std::string> data;
	data = ComputerFileManager::readFile();
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

			if(ComputerValidator::isValidCPU(cpu)) pc.setCPU(cpu);
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

			if(ComputerValidator::isValidGPU(gpu)) pc.setGPU(gpu);
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
				if(ComputerValidator::isValidRAMModule(ramModule)) pc.addRAM(ramModule);
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

			if(ComputerValidator::isValidStorage(storage)) pc.setStorage(storage);
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

			if(ComputerValidator::isValidPowerSupply(ps)) pc.setPowerSupply(ps);
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
			if(ComputerValidator::isValidMotherboard(mb)) pc.setMotherboard(mb);
		}
	}
}