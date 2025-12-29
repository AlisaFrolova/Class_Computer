#include "ConsoleView.h"
#include <iostream>

//Main menu
void ConsoleView::showMainMenu()
{
	cout << "\033[97m";
	cout << "\n--- Main menu ---\n";
	cout << "\033[0m";
	cout << "1. Change components\n";
	cout << "2. Check compatibility of the components\n";
	cout << "3. Check build state\n";
	cout << "4. Show computer's build\n";
	cout << "5. Clean build (delete)\n";
	cout << "\033[32m";
	cout << "0. Exit\n";
	cout << "\033[0m";
}
int ConsoleView::getMainMenuChoice()
{
	return inputInt("Choose an option: ", 0, 5);
}

//Edit menu
void ConsoleView::showComputerEditMenu()
{
	cout << "\033[97m";
	cout << "\n--- Edit menu ---\n";
	cout << "\033[0m";
	cout << "1. Change CPU\n";
	cout << "2. Change GPU\n";
	cout << "3. Change RAM\n";
	cout << "4. Change Storage\n";
	cout << "5. Change Power Supply\n";
	cout << "6. Change Motherboard\n";
	cout << "\033[32m";
	cout << "0. Back\n";
	cout << "\033[0m";
}
int ConsoleView::getComputerEditChoice()
{
	return inputInt("Choose an option: ", 0, 6);
}

//Computer menu
void ConsoleView::showComputerMenu()
{
	cout << "\033[97m";
	cout << "\n--- Computer menu ---\n";
	cout << "\033[0m";
	cout << "1. Show CPU\n";
	cout << "2. Show GPU\n";
	cout << "3. Show RAM\n";
	cout << "4. Show Storage\n";
	cout << "5. Show Power Supply\n";
	cout << "6. Show Motherboard\n";
	cout << "7. Show the whole build\n";
	cout << "\033[32m";
	cout << "0. Back\n";
	cout << "\033[0m";
}
int ConsoleView::getComputerMenuChoice()
{
	return inputInt("Choose an option: ", 0, 7);
}

//Check Compatibility Menu
void ConsoleView::showCompatibilityMenu()
{
	cout << "\033[97m";
	cout << "\n--- Compatibility menu ---\n";
	cout << "\033[0m";
	cout << "1. Check CPU/Motherboard compatibility\n";
	cout << "2. Check RAM/Motherboard compatibility\n";
	cout << "3. Check Power Supply power\n";
	cout << "\033[32m";
	cout << "0. Back\n";
	cout << "\033[0m";
}
int ConsoleView::getCompatibilityMenuChoice()
{
	return inputInt("Choose an option: ", 0, 3);
}

//Show
void ConsoleView::showMessage(const string& message)
{
	cout << "\033[33m";
	cout << message << endl;
	cout << "\033[0m";
}
void ConsoleView::showComputerComponent(const string& componentInfo)
{
	cout << "\033[36m";
	cout << componentInfo << endl;
	cout << "\033[0m";
}
void ConsoleView::showComputer(const vector<string>& computerInfo)
{
	cout << "\033[36m";
	for (const auto& s : computerInfo)
		cout << s << endl;
	cout << "\033[0m";
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
int ConsoleView::inputInt(const string& prompt, int min, int max)
{
	int value;
	while (true)
	{
		cout << prompt;
		if (cin >> value)
		{
			if (value >= min && value <= max)
			{
				cin.ignore(256, '\n');
				return value;
			}
			else
			{
				cout << "\033[34m" << "Number should be from [" << min << " to " << max << "]\n" << "\033[0m";
			}
		}
		else
		{
			cout << "\033[31m" << "Incorrect enter. Try again.\n" << "\033[0m\n";
			cin.clear();
			cin.ignore(256, '\n');
		}
	}
}
string ConsoleView::inputString(const string& prompt)
{
	string s;
	cout << prompt;
	getline(cin, s);

	if (s.empty())
		getline(cin, s);

	return s;
}

//staff
void ConsoleView::pause()
{
	cout << "\nEnter Enter to continue...";
	cin.ignore(256, '\n');
}