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

	//Show
	void showMessage(const string& message);
	void showComputerComponent(const string& componentInfo);
	void showComputer(const vector<string>& studentsInfo);

	//Enter data
	
private:
	//input data
	int inputInt(const string& prompt, int min, int max);
	string inputString(const string& prompt);
};

