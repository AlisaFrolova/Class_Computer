#pragma once

#include <iostream>
#include <string>

using namespace std;

class Motherboard
{
private:
	string model;
	string chipset;
	string formFactor;
	string socket;
	string typeOfRAM; //4xDDR5 for example
public:
	//constructor
	Motherboard(string m, string c, string f, string s, string t);

	//setters
	void setModel(const string& new_m);
	void setChipset(const string& new_c);
	void setFormFactor(const string& new_f);
	void setSocket(const string& new_s);
	void setTypeOfRAM(const string& new_t);

	//getters
	const string& getModel() const;
	const string& getChipset() const;
	const string& getFormFactor() const;
	const string& getSocket() const;
	const string& getTypeOfRAM() const;
};

