#pragma once
#include <iostream>
#include <string>

using namespace std;

class Storage
{
private:
	int capacity; //GB
	string type;
	int readSpeed; //MB/s
public:
	//constructor
	Storage();
	Storage(int c, string t, int rS);

	//setters
	void setCapacity(const int& new_c);
	void setType(const string& new_t);
	void setReadSpeed(const int& new_rS);

	//getters
	const int& getCapacity() const;
	const string& getType() const;
	const int& getReadSpeed() const;
};

