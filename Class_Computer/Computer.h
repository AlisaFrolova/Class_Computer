#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "CPU.h"
#include "GPU.h"
#include "RAM.h"
#include "Storage.h"
#include "PowerSupply.h"
#include "Motherboard.h"

class Computer
{
private:
    CPU cpu;
    GPU gpu;
    std::vector<RAM> ramModules;
    Storage storage;
    PowerSupply power_supply;
    Motherboard motherboard;

    //flags of existence
    bool hasCPU;
    bool hasGPU;
    bool hasStorage;
    bool hasPowerSupply;
    bool hasMotherboard;
public:
    //default constructor
    Computer();

    //setters
    void setCPU(const CPU& new_c);
    void setGPU(const GPU& new_g);
    void setStorage(const Storage& new_s);
    void setPowerSupply(const PowerSupply& new_ps);
    void setMotherboard(const Motherboard& new_m);

    //getters
    const CPU& getCPU() const;
    const GPU& getGPU() const;
    const std::vector<RAM>& getRAM() const;
    const Storage& getStorage() const;
    const PowerSupply& getPowerSupply() const;
    const Motherboard& getMotherboard() const;

    //RAM-work
    void addRAM(const RAM& new_module); 
    bool deleteRAM(const size_t index);

    //components check
    bool isCPUInstalled() const;
    bool isGPUInstalled() const;
    bool isRAMInstalled() const;
    bool isStorageInstalled() const;
    bool isPowerSupplyInstalled() const;
    bool isMotherboardInstalled() const;

    //build check
    bool isBuildReady() const;
};