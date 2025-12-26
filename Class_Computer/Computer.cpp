#include "Computer.h"
 
//constructor
Computer::Computer() { hasCPU = false; hasGPU = false; hasStorage = false; hasPowerSupply = false; hasMotherboard = false; }

//setters
bool Computer::setCPU(const CPU& new_c)
{
	if (!ComputerValidator::isValidCPU(new_c)) return false;
	cpu = new_c;
	return true;
}
bool Computer::setGPU(const GPU& new_g)
{
	if (!ComputerValidator::isValidGPU(new_g)) return false;
	gpu = new_g;
	return true;
}
bool Computer::setStorage(const Storage& new_s)
{
	if (!ComputerValidator::isValidStorage(new_s)) return false;
	storage = new_s;
	return true;
}
bool Computer::setPowerSupply(const PowerSupply& new_ps)
{
	if (!ComputerValidator::isValidPowerSupply(new_ps)) return false;
	power_supply = new_ps;
	return true;
}
bool Computer::setMotherboard(const Motherboard& new_m)
{
	if (!ComputerValidator::isValidMotherboard(new_m)) return false;
	motherboard = new_m;
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