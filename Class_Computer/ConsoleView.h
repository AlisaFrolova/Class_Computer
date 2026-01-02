#pragma once

#include <string>
#include <vector>

#include "InputData.h"

class ConsoleView
{
public:
	//Main menu
	void showMainMenu();
	int getMainMenuChoice();

	//Edit menu
	void showComputerEditMenu();
	int getComputerEditChoice();

	//RAM edit
	void showRAMIndex(std::vector <std::string> RAMInfo);
	int getRAMEditIndex();

	//Computer menu
	void showComputerMenu();
	int getComputerMenuChoice();

	//Check Compatibility menu
	void showCompatibilityMenu();
	int getCompatibilityMenuChoice();

	//Show
	void showMessage(const std::string& message);
	void showComputerComponent(const std::string& componentInfo);
	void showComputerComponents(const std::vector<std::string>& studentsInfo);

	//Enter data
	CPUInputData inputCPUData();
	GPUInputData inputGPUData();
	RAMInputData inputRAMData();
	StorageInputData inputStorageData();
	PowerSupplyInputData inputPowerSupplyData();
	MotherboardInputData inputMotherboardData();

	//staff
	void pause();
	
private:
	//input data
	int inputInt(const std::string& prompt, int min = INT_MIN, int max = INT_MAX);
	std::string inputString(const std::string& prompt);
};

