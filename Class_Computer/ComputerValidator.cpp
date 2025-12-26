#include "ComputerValidator.h"

bool ComputerValidator::isValidType(const string& type)
{
	return !type.empty();
}
bool ComputerValidator::isValidCPU(const CPU& cpu)
{
	if ((cpu.getModel().empty()) ||
	(cpu.getCoresNumber() <= 0) ||
	(cpu.getFrequency() <= 0) ||
	(cpu.getSocket().empty())) return false;
	else
	  return true;
}
bool ComputerValidator::isValidGPU(const GPU& gpu)
{
	if ((gpu.getModel().empty()) ||
	(gpu.getMemorySize() <= 0) ||
	(gpu.getPowerConsumption() <= 0)) return false;
	else
	  return true;
}
bool ComputerValidator::isValidRAMModule(const RAM& module)
{
	if ((module.getCapacity() <= 0) ||
		(module.getFrequency() <= 0) ||
		(module.getType().empty())) return false;
	else
	 return true;
}
bool ComputerValidator::areValidRAM(const vector <RAM>& ramModules)
{
	for (int i = 0; i < ramModules.size(); i++)
	{
		if ((ramModules.at(i).getCapacity() <= 0) ||
			(ramModules.at(i).getFrequency() <= 0) ||
			(ramModules.at(i).getType().empty())) return false;
	}

	  return true;
}
bool ComputerValidator::isValidStorage(const Storage& storage)
{
	if ((storage.getCapacity() <= 0) ||
		(storage.getType().empty()) ||
		(storage.getReadSpeed() <= 0)) return false;
	else
	  return true;
}
bool ComputerValidator::isValidPowerSupply(const PowerSupply& power_supply)
{
	if ((power_supply.getWattage() <= 0) ||
		(power_supply.getCertificate().empty())) return false;
	else
	  return true;
}
bool ComputerValidator::isValidMotherboard(const Motherboard& motherboard)
{
	if ((motherboard.getModel().empty()) ||
		(motherboard.getChipset().empty()) ||
		(motherboard.getFormFactor().empty()) ||
		(motherboard.getSocket().empty()) ||
		(motherboard.getTypeOfRAM().empty())) return false;
	else
	  return true;
}