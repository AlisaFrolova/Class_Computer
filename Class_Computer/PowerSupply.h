#pragma once

#include <iostream>
#include <string>

using namespace std;

class PowerSupply
{
private:
	int wattage;
	string certificate;
public:
	//constructor
	PowerSupply();
	PowerSupply(int w, string c);

	//setters
	void setWattage(const int& new_w);
	void setCertificate(const string& new_c);

	//getters
	const int& getWattage() const;
	const string& getCertificate() const;
};

