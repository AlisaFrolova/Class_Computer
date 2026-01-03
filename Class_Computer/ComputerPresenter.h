#pragma once

#include <vector>
#include <string>

#include "Computer.h"
#include "ConsoleView.h"
#include "InputData.h"
#include "ComputerValidator.h"
#include "ComputerFileManager.h"

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

    //Info of components
    std::string getCPUInfo() const;
    std::string getGPUInfo() const;
    std::string getRAMInfo() const;
    std::string getStorageInfo() const;
    std::string getPowerSupplyInfo() const;
    std::string getMotherboardInfo() const;

    //File work
    void writeFileData();
    void readFileData();
};