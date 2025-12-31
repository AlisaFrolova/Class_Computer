#include "Motherboard.h"

//constructor
Motherboard::Motherboard() {}
Motherboard::Motherboard(std::string m, std::string c, std::string f, std::string s, std::string t) : model(m), chipset(c), formFactor(f), socket(s), typeOfRAM(t) {}

//setters
void Motherboard::setModel(const std::string& new_m)
{
	model = new_m;
}
void Motherboard::setChipset(const std::string& new_c)
{
	chipset = new_c;
}
void Motherboard::setFormFactor(const std::string& new_f)
{
	formFactor = new_f;
}
void Motherboard::setSocket(const std::string& new_s)
{
	socket = new_s;
}
void Motherboard::setTypeOfRAM(const std::string& new_t)
{
	typeOfRAM = new_t;
}

//getters
const std::string& Motherboard::getModel() const
{
	return model;
}
const std::string& Motherboard::getChipset() const
{
	return chipset;
}
const std::string& Motherboard::getFormFactor() const
{
	return formFactor;
}
const std::string& Motherboard::getSocket() const
{
	return socket;
}
const std::string& Motherboard::getTypeOfRAM() const
{
	return typeOfRAM;
}