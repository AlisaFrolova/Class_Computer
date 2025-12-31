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

    std::string getCPUInfo() const;
    std::string getGPUInfo() const;
    std::string getRAMInfo() const;
    std::string getStorageInfo() const;
    std::string getPowerSupplyInfo() const;
    std::string getMotherboardInfo() const;

    void writeFileData();
    void readFileData();
};


