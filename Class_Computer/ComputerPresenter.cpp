#include "ComputerPresenter.h"

ComputerPresenter::ComputerPresenter(Computer& pc, ConsoleView& view) : pc(pc), view(view){}

void ComputerPresenter::run()
{
	createComputerFromFile();
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
		case 6: saveComputer(); break; 
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
			view.showComputerComponent(ComputerManager::getCPUInfo(pc));
			break;
		}
		case 2:
		{
			view.showComputerComponent(ComputerManager::getGPUInfo(pc));
			break;
		}
		case 3: 
		{
			view.showComputerComponent(ComputerManager::getRAMInfo(pc));
			break;
		}
		case 4: 
		{
			view.showComputerComponent(ComputerManager::getStorageInfo(pc));
			break;
		}
		case 5: 
		{
			view.showComputerComponent(ComputerManager::getPowerSupplyInfo(pc));
			break;
		}
		case 6:
		{
			view.showComputerComponent(ComputerManager::getMotherboardInfo(pc));
			break;
		}
		case 7:
		{
			view.showComputerComponent(ComputerManager::getCPUInfo(pc));
			view.showComputerComponent(ComputerManager::getGPUInfo(pc));
			view.showComputerComponent(ComputerManager::getRAMInfo(pc));
			view.showComputerComponent(ComputerManager::getStorageInfo(pc));
			view.showComputerComponent(ComputerManager::getPowerSupplyInfo(pc));
			view.showComputerComponent(ComputerManager::getMotherboardInfo(pc));
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
			if (ComputerManager::areCPUAndMotherboardCompatible(pc)) view.showMessage("CPU and Motherboard are compatible!");
			else
			   view.showMessage("CPU and/or Motherboard are not compatible or not installed!");
		break;
		}
		case 2:
		{
		    if (ComputerManager::areRAMAndMotherboardCompatible(pc)) view.showMessage("RAM and Motherboard are compatible!");
		    else
		       view.showMessage("RAM and/or Motherboard are not compatible or not installed!");
		break;
		}
		case 3:
		{
			if (ComputerManager::isPowerSupplyPowerful(pc)) view.showMessage("Power Supply is powerful enough for current build!");
			else
				view.showMessage("Power Supply is not powerful enough or not installed!");
			break;
		}
		case 4:
		{
			if (ComputerManager::isComputerPowerful(pc)) view.showMessage("Computer is powerful!");
			else
				view.showMessage("Build is not completed or not very powerful!");
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

void ComputerPresenter::saveComputer()
{
	if (pc.isBuildReady())
	{
		ComputerFileManager::writeFile(ComputerManager::writeFileData(pc));
		view.showMessage("Build has been saved!");
	}
	else
		view.showMessage("Cannot save. Build is not completed!");
}

void ComputerPresenter::createComputerFromFile()
{
	std::vector <std::string> data;
	data = ComputerFileManager::readFile();
	Computer temp_pc = ComputerManager::readFileData(data);

	if (ComputerValidator::isValidCPU(temp_pc.getCPU())
		&& ComputerValidator::isValidGPU(temp_pc.getGPU())
		&& ComputerValidator::areValidRAM(temp_pc.getRAM())
		&& ComputerValidator::isValidStorage(temp_pc.getStorage())
		&& ComputerValidator::isValidPowerSupply(temp_pc.getPowerSupply())
		&& ComputerValidator::isValidMotherboard(temp_pc.getMotherboard()))
		pc = temp_pc;
}