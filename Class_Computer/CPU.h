#pragma once

#include <iostream>
#include <string>

using namespace std;

class CPU
{
private:
	string model;
	int coresNumber;
	double frequency; //GHz
public:
	//constructor
	CPU(string m, int cn, double f);

	//setters 
	void setModel(const string &new_m);
	void setCoresNumber(const int& new_cn);
	void setFrequency(const double &new_f);

	//getters
	const string& getModel() const;
	const int& getCoresNumber() const;
	const double& getFrequency() const;
};

