#include "PowerSupply.h"

//constructor
PowerSupply::PowerSupply() {}
PowerSupply::PowerSupply(int w, std::string c) : wattage(w), certificate(c){}

//setters
void PowerSupply::setWattage(const int& new_w)
{
	wattage = new_w;
}
void PowerSupply::setCertificate(const std::string& new_c)
{
	certificate = new_c;
}

//getters
const int& PowerSupply::getWattage() const
{
	return wattage;
}
const std::string& PowerSupply::getCertificate() const
{
	return certificate;
}