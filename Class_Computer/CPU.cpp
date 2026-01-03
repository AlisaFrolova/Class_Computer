#include "CPU.h"

//constructors
CPU::CPU() {} 
CPU::CPU(std::string m, int cn, int f, std::string s) : model(m), coresNumber(cn), frequency(f), socket(s){}

//setters 
void CPU::setModel(const std::string& new_m)
{
	model = new_m;
}
void CPU::setCoresNumber(const int& new_cn)
{
	coresNumber = new_cn;
}
void CPU::setFrequency(const int& new_f)
{
	frequency = new_f;
}
void CPU::setSocket(const std::string& new_s)
{
	socket = new_s;
}

//getters
const std::string& CPU::getModel() const
{
	return model;
}
const int& CPU::getCoresNumber() const
{
	return coresNumber;
}
const int& CPU::getFrequency() const
{
	return frequency;
}
const std::string& CPU::getSocket() const
{
	return socket;
}