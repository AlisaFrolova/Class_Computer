#pragma once

#include <iostream>
#include <string>

class PowerSupply
{
private:
	int wattage;
	std::string certificate;
public:
	//constructor
	PowerSupply();
	PowerSupply(int w, std::string c);

	//setters
	void setWattage(const int& new_w);
	void setCertificate(const std::string& new_c);

	//getters
	const int& getWattage() const;
	const std::string& getCertificate() const;
};

