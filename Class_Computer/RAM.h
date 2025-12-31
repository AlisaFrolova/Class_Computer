#pragma once

#include <iostream>
#include <string>

class RAM
{
private:
	int capacity; //GB
	std::string type;
	int frequency; //MHz
public:
	//constructor
	RAM(int c, std::string t, int f);

	//setters
	void setCapacity(const int& new_c);
	void setType(const std::string& new_t);
	void setFrequency(const int& new_f);

	//getters
	const int& getCapacity() const;
	const std::string& getType() const;
	const int& getFrequency() const;
};

