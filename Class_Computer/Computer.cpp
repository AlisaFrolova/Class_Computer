#include "Computer.h"

//constructor
Computer::Computer()
    : hasCPU(false), hasGPU(false), hasStorage(false), hasPowerSupply(false), hasMotherboard(false) {
}

//setters
void Computer::setCPU(const CPU& new_c)
{
    cpu = new_c;
    hasCPU = true;
}
void Computer::setGPU(const GPU& new_g)
{
    gpu = new_g;
    hasGPU = true;
}
void Computer::setStorage(const Storage& new_s)
{
    storage = new_s;
    hasStorage = true;
}
void Computer::setPowerSupply(const PowerSupply& new_ps)
{
    power_supply = new_ps;
    hasPowerSupply = true;
}
void Computer::setMotherboard(const Motherboard& new_m)
{
    motherboard = new_m;
    hasMotherboard = true;
}

//getters
const CPU& Computer::getCPU() const
{
    return cpu;
}
const GPU& Computer::getGPU() const
{
    return gpu;
}
const std::vector<RAM>& Computer::getRAM() const
{
    return ramModules;
}
const Storage& Computer::getStorage() const
{
    return storage;
}
const PowerSupply& Computer::getPowerSupply() const
{
    return power_supply;
}
const Motherboard& Computer::getMotherboard() const
{
    return motherboard;
}

//RAM-work
void Computer::addRAM(const RAM& new_ram)
{
    ramModules.push_back(new_ram);
}
bool Computer::deleteRAM(const size_t index)
{
    if (index >= ramModules.size()) return false;

    ramModules.erase(ramModules.begin() + index);
    return true;
}

bool Computer::isCPUInstalled() const
{
    return hasCPU;
}
bool Computer::isGPUInstalled() const
{
    return hasGPU;
}
bool Computer::isRAMInstalled() const
{
    return !ramModules.empty();
}
bool Computer::isStorageInstalled() const
{
    return hasStorage;
}
bool Computer::isPowerSupplyInstalled() const
{
    return hasPowerSupply;
}
bool Computer::isMotherboardInstalled() const
{
    return hasMotherboard;
}

bool Computer::isBuildReady() const
{
    return isCPUInstalled() && isGPUInstalled() && isRAMInstalled() &&
        isStorageInstalled() && isPowerSupplyInstalled() && isMotherboardInstalled();
}
