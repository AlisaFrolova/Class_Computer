#include "GPU.h"

//constructors
GPU::GPU() {}
GPU::GPU(std::string m, int mS, int pC) : model(m), memorySize(mS), powerConsumption(pC){}

//setters
void GPU::setModel(const std::string& new_m)
{
	model = new_m;
}
void GPU::setMemorySize(const int& new_ms)
{
	memorySize = new_ms;
}
void GPU::setPowerConsumption(const int& new_pc)
{
	powerConsumption = new_pc;
}

//getters
const std::string& GPU::getModel() const
{
	return model;
}
const int& GPU::getMemorySize() const
{
	return memorySize;
}
const int& GPU::getPowerConsumption() const
{
	return powerConsumption;
}