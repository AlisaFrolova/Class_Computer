#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "CPU.h"
#include "GPU.h"
#include "RAM.h"
#include "Storage.h"
#include "PowerSupply.h"
#include "Motherboard.h"

using namespace std;

class Computer
{
private:
	string type;
	CPU cpu;
	GPU gpu;
	vector <RAM> ram;
	Storage storage;
	PowerSupply power_supply;
	Motherboard motherboard;
};

