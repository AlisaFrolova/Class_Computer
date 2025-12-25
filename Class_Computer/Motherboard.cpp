#include "Motherboard.h"

//constructor
Motherboard::Motherboard(string m, string c, string f, string s, string t) : model(m), chipset(c), formFactor(f), socket(s), typeOfRAM(t) {}

//setters
void Motherboard::setModel(const string& new_m)
{
	model = new_m;
}
void Motherboard::setChipset(const string& new_c)
{
	chipset = new_c;
}
void Motherboard::setFormFactor(const string& new_f)
{
	formFactor = new_f;
}
void Motherboard::setSocket(const string& new_s)
{
	socket = new_s;
}
void Motherboard::setTypeOfRAM(const string& new_t)
{
	typeOfRAM = new_t;
}

//getters
const string& Motherboard::getModel() const
{
	return model;
}
const string& Motherboard::getChipset() const
{
	return chipset;
}
const string& Motherboard::getFormFactor() const
{
	return formFactor;
}
const string& Motherboard::getSocket() const
{
	return socket;
}
const string& Motherboard::getTypeOfRAM() const
{
	return typeOfRAM;
}