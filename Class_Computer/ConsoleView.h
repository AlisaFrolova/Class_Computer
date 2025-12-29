#pragma once

#include <string>
#include <vector>

#include "InputData.h"

using namespace std;

class ConsoleView
{
public:
	//Main menu
	void showMainMenu();
	int getMainMenuChoice();

	//Edit menu
	void showComputerEditMenu();
	int getComputerEditChoice();

	//Computer menu
	void showComputerMenu();
	int getComputerMenuChoice();

	//Check Compatibility menu
	void showCompatibilityMenu();
	int getCompatibilityMenuChoice();

	//Show
	void showMessage(const string& message);
	void showComputerComponent(const string& componentInfo);
	void showComputer(const vector<string>& studentsInfo);

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
	int inputInt(const string& prompt, int min = INT_MIN, int max = INT_MAX);
	string inputString(const string& prompt);
};

