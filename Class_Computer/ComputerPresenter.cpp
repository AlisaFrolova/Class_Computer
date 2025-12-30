#include "ComputerPresenter.h"
#include "CPU.h"

using namespace std;

ComputerPresenter::ComputerPresenter(Computer& pc, ConsoleView& view) : pc(pc), view(view){}

void ComputerPresenter::run()
{
	bool running = true;
	while (running)
	{
		view.showMainMenu();
		int choice = view.getMainMenuChoice();

		switch (choice)
		{
		case 1: changeComputer(); break; // +
		case 2: checkCompatibility(); break;//+
		case 3: checkBuildState(); break; //+
		case 4: showComputer(); break; //+
		case 5: cleanComputer(); break; //+
		case 0: running = false; break; //+
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
		case 5:
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
		case 6:
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
			view.showComputer(getRAMInfo());
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
			view.showComputer(getRAMInfo());
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
string ComputerPresenter::getCPUInfo() 
{
	if (pc.isCPUInstalled())
	{
		string CPU_data = "CPU info: \n" + pc.getCPU().getModel() + " " + to_string(pc.getCPU().getCoresNumber()) + " " + to_string(pc.getCPU().getFrequency()) + " " + pc.getCPU().getSocket();
		return CPU_data;
	}
	else
		return "CPU is not installed!";
}
string ComputerPresenter::getGPUInfo() 
{
	if (pc.isGPUInstalled())
	{
		string GPU_data = "GPU info: \n" + pc.getGPU().getModel() + " " + to_string(pc.getGPU().getMemorySize()) + " " + to_string(pc.getGPU().getPowerConsumption());
		return GPU_data;
	}
	else
		return "GPU is not installed!";
}
vector <string> ComputerPresenter::getRAMInfo() 
{
	vector<string> RAM_data;
	if (pc.isRAMInstalled())
	{
		RAM_data.push_back("Number of Modules: " + to_string(pc.getRAM().size()));
		for (int i = 0; i < pc.getRAM().size(); i++)
		{
			RAM_data.push_back(to_string(pc.getRAM().at(i).getCapacity()) + " " + pc.getRAM().at(i).getType() + " " + to_string(pc.getRAM().at(i).getFrequency()));
		}
		return RAM_data;
	}
	else
	{
		RAM_data.push_back("RAM is not installed!");
		return RAM_data;
	}
}
string ComputerPresenter::getStorageInfo() 
{
	if (pc.isStorageInstalled())
	{
		string Storage_data = "Storage info: \n" + to_string(pc.getStorage().getCapacity()) + " " + pc.getStorage().getType() + " " + to_string(pc.getStorage().getReadSpeed());
		return Storage_data;
	}
	else
		return "Storage is not installed!";
}
string ComputerPresenter::getPowerSupplyInfo()
{
	if (pc.isPowerSupplyInstalled())
	{
		string PowerSupply_data = "Power Supply info: \n" + to_string(pc.getPowerSupply().getWattage()) + " " + pc.getPowerSupply().getCertificate();
		return PowerSupply_data;
	}
	else
		return "Power Supply is not installed!";
}
string ComputerPresenter::getMotherboardInfo()
{
	if (pc.isMotherboardInstalled())
	{
		string Motherboard_data = "Motherboard info: \n" + pc.getMotherboard().getModel() + " " + pc.getMotherboard().getChipset() + " " + pc.getMotherboard().getFormFactor() + " " + pc.getMotherboard().getSocket() + " " + pc.getMotherboard().getTypeOfRAM();
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
				view.showMessage("1. CPU and Motherboard are not compatible!");
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
				string ram_data = to_string(pc.getRAM().size()) + "x" + pc.getRAM().at(i).getType();
				if (ram_data != pc.getMotherboard().getTypeOfRAM()) ram_comp = false;
			}
			if (ram_comp) view.showMessage("2. RAM and Motherboard are compatible!");
			else
				view.showMessage("2. RAM and Motherboard are not compatible!");
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
					view.showMessage("3. Power Supply is powerful enough for current build!");
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