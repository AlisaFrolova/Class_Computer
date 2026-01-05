#pragma once

#include <vector>
#include <string>

#include "Computer.h"
#include "ConsoleView.h"
#include "InputData.h"
#include "ComputerValidator.h"
#include "ComputerFileManager.h"
#include "ComputerManager.h"

class ComputerPresenter
{
public:
    //constructor
    ComputerPresenter(Computer& pc, ConsoleView& view);

    void run();
private:
    Computer& pc;
    ConsoleView& view;

    //methods
    void changeComputer();
    void cleanComputer();
    void showComputer();
    void checkBuildState();
    void checkCompatibility();

    //File work (parsers)
    void saveComputer();
    void createComputerFromFile();
};