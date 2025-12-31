#pragma once

#include <iostream>
#include <string>

class CPU
{
private:
	std::string model;
	int coresNumber;
	int frequency; //MHz
	std::string socket;
public:
	//constructor
	CPU();
	CPU(std::string m, int cn, int f, std::string s);

	//setters 
	void setModel(const std::string &new_m);
	void setCoresNumber(const int& new_cn);
	void setFrequency(const int &new_f);
	void setSocket(const std::string& new_s);

	//getters
	const std::string& getModel() const;
	const int& getCoresNumber() const;
	const int& getFrequency() const;
	const std::string& getSocket() const;
};

