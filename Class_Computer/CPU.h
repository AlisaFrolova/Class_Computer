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
	string socket; 
public:
	//constructor
	CPU();
	CPU(string m, int cn, double f, string s);

	//setters 
	void setModel(const string &new_m);
	void setCoresNumber(const int& new_cn);
	void setFrequency(const double &new_f);
	void setSocket(const string& new_s);

	//getters
	const string& getModel() const;
	const int& getCoresNumber() const;
	const double& getFrequency() const;
	const string& getSocket() const;
};

