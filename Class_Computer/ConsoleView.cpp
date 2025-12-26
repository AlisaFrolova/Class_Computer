#include "ConsoleView.h"
#include <iostream>

//Main menu
void ConsoleView::showMainMenu()
{
	cout << "\n--- Main menu ---\n";
	cout << "1. Change components\n";
	cout << "2. Check compatibility of the components\n";
	cout << "3. Check build state\n";
	cout << "4. Show the whole build\n";
	cout << "5. Show one of the components\n";
	cout << "6. Clean build (delete)\n";
	cout << "0. Exit\n";
}
int ConsoleView::getMainMenuChoice()
{
	return inputInt("Choose an option: ", 0, 6);
}

//Edit menu
void ConsoleView::showComputerEditMenu()
{
	cout << "\n--- Edit menu ---\n";
	cout << "1. Change CPU\n";
	cout << "2. Change GPU\n";
	cout << "3. Change RAM\n";
	cout << "4. Change Storage\n";
	cout << "5. Change Power Supply\n";
	cout << "6. Change Motherboard\n";
	cout << "0. Back\n";
}
int ConsoleView::getComputerEditChoice()
{
	return inputInt("Choose an option: ", 0, 6);
}

//Show
void ConsoleView::showMessage(const string& message)
{
	cout << message << endl;
}
void ConsoleView::showComputerComponent(const string& componentInfo)
{
	cout << componentInfo << endl;
}
void ConsoleView::showComputer(const vector<string>& computerInfo)
{
	for (const auto& s : computerInfo)
		cout << s << endl;
}

//Enter data


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
				cout << "Number should be from [" << min << " to " << max << "]\n";
			}
		}
		else
		{
			cout << "Incorrect enter. Try again.\n";
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