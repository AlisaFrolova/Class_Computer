#include "RAM.h"

//constructor
RAM::RAM(int c, string t, int f) : capacity(c), type(t), frequency(f) {}

//setters
void RAM::setCapacity(const int& new_c)
{
	capacity = new_c;
}
void RAM::setType(const string& new_t)
{
	type = new_t;
}
void RAM::setFrequency(const int& new_f)
{
	frequency = new_f;
}

//getters
const int& RAM::getCapacity() const
{
	return capacity;
}
const string& RAM::getType() const
{
	return type;
}
const int& RAM::getFrequency() const
{
	return frequency;
}