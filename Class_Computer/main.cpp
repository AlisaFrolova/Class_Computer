#include <iostream>

#include "Computer.h"
#include "ConsoleView.h"
#include "ComputerPresenter.h"

int main()
{
	Computer pc;
	ConsoleView view;
	ComputerPresenter presenter(pc, view);
	presenter.run();
	return 0;
}