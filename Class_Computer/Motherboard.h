#pragma once

#include <string>

class Motherboard
{
private:
	std::string model;
	std::string chipset;
	std::string formFactor;
	std::string socket;
	std::string typeOfRAM; //4xDDR5 for example
public:
	//constructors
	Motherboard();
	Motherboard(std::string m, std::string c, std::string f, std::string s, std::string t);

	//setters
	void setModel(const std::string& new_m);
	void setChipset(const std::string& new_c);
	void setFormFactor(const std::string& new_f);
	void setSocket(const std::string& new_s);
	void setTypeOfRAM(const std::string& new_t);

	//getters
	const std::string& getModel() const;
	const std::string& getChipset() const;
	const std::string& getFormFactor() const;
	const std::string& getSocket() const;
	const std::string& getTypeOfRAM() const;
};