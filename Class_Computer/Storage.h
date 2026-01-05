#pragma once

#include <string>

class Storage
{
private:
	int capacity; //GB
	std::string type;
	int readSpeed; //MB/s
public:
	//constructors
	Storage();
	Storage(int c, std::string t, int rS);

	//setters
	void setCapacity(const int& new_c);
	void setType(const std::string& new_t);
	void setReadSpeed(const int& new_rS);

	//getters
	const int& getCapacity() const;
	const std::string& getType() const;
	const int& getReadSpeed() const;
};