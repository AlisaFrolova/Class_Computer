#include "Computer.h"
 
//constructor
Computer::Computer() { hasCPU = false; hasGPU = false; hasStorage = false; hasPowerSupply = false; hasMotherboard = false; }

//setters
void Computer::setType(const string& new_t)
{

}
void Computer::setCPU(const CPU& new_c)
{

}
void Computer::setGPU(const GPU& new_g)
{

}
void Computer::setStorage(const Storage& new_s)
{

}
void Computer::setPowerSupply(const PowerSupply& new_ps)
{

}
void Computer::setMotherboard(const Motherboard& new_m)
{

}

//getters
const string& Computer::getType()const
{
	return type;
}
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
bool Computer::addRAM(RAM new_ram)
{
	return true;
}