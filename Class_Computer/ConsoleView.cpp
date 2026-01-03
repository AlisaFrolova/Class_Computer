#include "ConsoleView.h"

//Main menu
void ConsoleView::showMainMenu()
{
	std::cout << "\033[97m";
	std::cout << "\n--- Main menu ---\n";
	std::cout << "\033[0m";
	std::cout << "1. Change components\n";
	std::cout << "2. Check compatibility of the components\n";
	std::cout << "3. Check build state\n";
	std::cout << "4. Show computer's build\n";
	std::cout << "5. Clean build (delete)\n";
	std::cout << "6. Save build\n";
	std::cout << "\033[32m";
	std::cout << "0. Exit\n";
	std::cout << "\033[0m";
}
int ConsoleView::getMainMenuChoice()
{
	return inputInt("Choose an option: ", 0, 6);
}

//Edit menu
void ConsoleView::showComputerEditMenu()
{
	std::cout << "\033[97m";
	std::cout << "\n--- Edit menu ---\n";
	std::cout << "\033[0m";
	std::cout << "1. Change CPU\n";
	std::cout << "2. Change GPU\n";
	std::cout << "3. Add RAM module\n";
	std::cout << "4. Delete RAM module\n";
	std::cout << "5. Change Storage\n";
	std::cout << "6. Change Power Supply\n";
	std::cout << "7. Change Motherboard\n";
	std::cout << "\033[32m";
	std::cout << "0. Back\n";
	std::cout << "\033[0m";
}
int ConsoleView::getComputerEditChoice()
{
	return inputInt("Choose an option: ", 0, 7);
}

void ConsoleView::showRAMByIndex(std::vector <std::string> RAMInfo)
{
	for (int i = 0; i < RAMInfo.size(); i++)
	{
		std::cout << i + 1 << ". " << RAMInfo.at(i) << std::endl;
	}
}
int ConsoleView::getRAMEditIndex()
{
	return inputInt("Enter index of RAM module: ", 1);
}

//Computer menu
void ConsoleView::showComputerMenu()
{
	std::cout << "\033[97m";
	std::cout << "\n--- Computer menu ---\n";
	std::cout << "\033[0m";
	std::cout << "1. Show CPU\n";
	std::cout << "2. Show GPU\n";
	std::cout << "3. Show RAM\n";
	std::cout << "4. Show Storage\n";
	std::cout << "5. Show Power Supply\n";
	std::cout << "6. Show Motherboard\n";
	std::cout << "7. Show the whole build\n";
	std::cout << "\033[32m";
	std::cout << "0. Back\n";
	std::cout << "\033[0m";
}
int ConsoleView::getComputerMenuChoice()
{
	return inputInt("Choose an option: ", 0, 7);
}

//Check Compatibility Menu
void ConsoleView::showCompatibilityMenu()
{
	std::cout << "\033[97m";
	std::cout << "\n--- Compatibility menu ---\n";
	std::cout << "\033[0m";
	std::cout << "1. Check CPU/Motherboard compatibility\n";
	std::cout << "2. Check RAM/Motherboard compatibility\n";
	std::cout << "3. Check Power Supply power\n";
	std::cout << "4. Check Computer power\n";
	std::cout << "\033[32m";
	std::cout << "0. Back\n";
	std::cout << "\033[0m";
}
int ConsoleView::getCompatibilityMenuChoice()
{
	return inputInt("Choose an option: ", 0, 4);
}

//Show
void ConsoleView::showMessage(const std::string& message)
{
	std::cout << "\033[33m";
	std::cout << message << std::endl;
	std::cout << "\033[0m";
}
void ConsoleView::showComputerComponent(const std::string& componentInfo)
{
	std::cout << "\033[36m";
	std::cout << componentInfo << std::endl;
	std::cout << "\033[0m";
}
void ConsoleView::showComputerComponents(const std::vector<std::string>& computerInfo)
{
	std::cout << "\033[36m";
	for (const auto& s : computerInfo)
		std::cout << s << std::endl;
	std::cout << "\033[0m";
}

//Enter data
CPUInputData ConsoleView::inputCPUData()
{
	CPUInputData data;
	data.model = inputString("Enter model of CPU: ");
	data.cores = inputInt("Enter number of cores for CPU: ");
	data.frequency = inputInt("Enter frequency of CPU (MHz) : ");
	data.socket = inputString("Enter socket of CPU: ");

	return data;
}
GPUInputData ConsoleView::inputGPUData()
{
	GPUInputData data;
	data.model = inputString("Enter model of GPU : ");
	data.memorySize = inputInt("Enter memory size of GPU (GB) : ");
	data.powerConsumption = inputInt("Enter power consumption of GPU (Watts) : ");

	return data;
}
RAMInputData ConsoleView::inputRAMData()
{
	RAMInputData data;
	data.capacity = inputInt("Enter capacity of RAM module (GB) : ");
	data.type = inputString("Enter type of RAM module (For example, DDR5) : ");
	data.frequency = inputInt("Enter frequency of RAM module (MHz) : ");

	return data;
}
StorageInputData ConsoleView::inputStorageData()
{
	StorageInputData data;
	data.capacity = inputInt("Enter capacity of Storage (GB) : ");
	data.type = inputString("Enter type of storage (For example, HDD or SSD) : ");
	data.readSpeed = inputInt("Enter read speed of storage (MB/s) : ");

	return data;
}
PowerSupplyInputData ConsoleView::inputPowerSupplyData()
{
	PowerSupplyInputData data;
	data.wattage = inputInt("Enter wattage of power supply (Watts) : ");
	data.certificate = inputString("Enter certificate of power supply (For example, Platinum, Gold and etc.) : ");

	return data;
}
MotherboardInputData ConsoleView::inputMotherboardData()
{
	MotherboardInputData data;
	data.model = inputString("Enter model of motherboard: ");
	data.chipset = inputString("Enter chipset of motherboard: ");
	data.formFactor = inputString("Enter form factor of motherboard: ");
	data.socket = inputString("Enter socket of motherboard: ");
	data.typeOfRAM = inputString("Enter type of RAM of motherboard (For example, 4xDDR5) : ");

	return data;
}

//input data
int ConsoleView::inputInt(const std::string& prompt, int min, int max)
{
	int value;
	while (true)
	{
		std::cout << prompt;
		if (std::cin >> value)
		{
			if (value >= min && value <= max)
			{
				std::cin.ignore(256, '\n');
				return value;
			}
			else
			{
				std::cout << "\033[34m" << "Number should be from [" << min << " to " << max << "]\n" << "\033[0m";
			}
		}
		else
		{
			std::cout << "\033[31m" << "Incorrect enter. Try again.\n" << "\033[0m\n";
			std::cin.clear();
			std::cin.ignore(256, '\n');
		}
	}
}
std::string ConsoleView::inputString(const std::string& prompt)
{
	std::string s;
	std::cout << prompt;
	getline(std::cin, s);

	if (s.empty())
		getline(std::cin, s);

	return s;
}