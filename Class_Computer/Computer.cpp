#include "Computer.h"
 
//constructor
Computer::Computer() { hasCPU = false; hasGPU = false; hasStorage = false; hasPowerSupply = false; hasMotherboard = false; }

//setters
bool Computer::setCPU(const CPU& new_c)
{
	if (!ComputerValidator::isValidCPU(new_c)) return false;
	cpu = new_c;
	hasCPU = true;
	return true;
}
bool Computer::setGPU(const GPU& new_g)
{
	if (!ComputerValidator::isValidGPU(new_g)) return false;
	gpu = new_g;
	hasGPU = true;
	return true;
}
bool Computer::setStorage(const Storage& new_s)
{
	if (!ComputerValidator::isValidStorage(new_s)) return false;
	storage = new_s;
	hasStorage = true;
	return true;
}
bool Computer::setPowerSupply(const PowerSupply& new_ps)
{
	if (!ComputerValidator::isValidPowerSupply(new_ps)) return false;
	power_supply = new_ps;
	hasPowerSupply = true;
	return true;
}
bool Computer::setMotherboard(const Motherboard& new_m)
{
	if (!ComputerValidator::isValidMotherboard(new_m)) return false;
	motherboard = new_m;
	hasMotherboard = true;
	return true;
}

//getters
const CPU& Computer::getCPU()const
{
	return cpu;
}
const GPU& Computer::getGPU()const
{
	return gpu;
}
const vector<RAM>&  Computer::getRAM() const
{
	return ramModules;
}
const Storage& Computer::getStorage()const
{
	return storage;
}
const PowerSupply& Computer::getPowerSupply()const
{
	return power_supply;
}
const Motherboard& Computer::getMotherboard()const
{
	return motherboard;
}

//RAM-work
bool Computer::addRAM(RAM& new_ram)
{
	if (!ComputerValidator::isValidRAMModule(new_ram)) return false;
	ramModules.push_back(new_ram);
	return true;
}

bool Computer::isCPUInstalled() const
{
	if (hasCPU) return true;
	else
		return false;
}
bool Computer::isGPUInstalled() const
{
	if (hasGPU) return true;
	else
		return false;
}
bool Computer::isRAMInstalled() const
{
	if (ramModules.size() > 0) return true;
	else
		return false;
}
bool Computer::isStorageInstalled() const
{
	if (hasStorage) return true;
	else
		return false;
}
bool Computer::isPowerSupplyInstalled() const
{
	if (hasPowerSupply) return true;
	else
		return false;
}
bool Computer::isMotherboardInstalled() const
{
	if (hasMotherboard) return true;
	else
		return false;
}

bool Computer::isBuildReady() const
{
	if (isCPUInstalled() && isGPUInstalled() && isRAMInstalled() && isStorageInstalled() && isPowerSupplyInstalled() && isMotherboardInstalled()) return true;
	else
		return false;
}