#pragma once

#include "Computer.h"
#include "ComputerValidator.h"
#include "ConsoleView.h"
#include "InputData.h"

class ComputerPresenter
{
public:
	ComputerPresenter(Computer& pc, ConsoleView& view);

	void run();
private:
	Computer& pc;
	ConsoleView& view;

	//methods
	void changeComputer();
	void cleanComputer();
	void showComputer();
	void showComponent();
	void checkBuildState();
};

