#include "Storage.h"

//constructor
Storage::Storage() {}
Storage::Storage(int c, string t, int rS) : capacity(c), type(t), readSpeed(rS){}

//setters
void Storage::setCapacity(const int& new_c)
{
	capacity = new_c;
}
void Storage::setType(const string& new_t)
{
	type = new_t;
}
void Storage::setReadSpeed(const int& new_rS)
{
	readSpeed = new_rS;
}

//getters
const int& Storage::getCapacity() const
{
	return capacity;
}
const string& Storage::getType() const
{
	return type;
}
const int& Storage::getReadSpeed() const
{
	return readSpeed;
}