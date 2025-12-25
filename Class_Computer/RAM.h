#pragma once

#include <iostream>
#include <string>

using namespace std;

class RAM
{
private:
	int capacity; //GB
	string type;
	int frequency; //MHz
public:
	//constructor
	RAM(int c, string t, int f);

	//setters
	void setCapacity(const int& new_c);
	void setType(const string& new_t);
	void setFrequency(const int& new_f);

	//getters
	const int& getCapacity() const;
	const string& getType() const;
	const int& getFrequency() const;
};

