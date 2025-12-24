#include "CPU.h"

//constructor
CPU::CPU(string m, int cn, double f) : model(m), coresNumber(cn), frequency(f){}

//setters 
void CPU::setModel(const string& new_m) 
{
	model = new_m;
}
void CPU::setCoresNumber(const int& new_cn)
{
	coresNumber = new_cn;
}
void CPU::setFrequency(const double& new_f)
{
	frequency = new_f;
}

//getters
const string& CPU::getModel() const
{
	return model;
}
const int& CPU::getCoresNumber() const
{
	return coresNumber;
}
const double& CPU::getFrequency() const
{
	return frequency;
}