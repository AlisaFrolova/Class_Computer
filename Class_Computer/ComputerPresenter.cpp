#include "ComputerPresenter.h"
#include "CPU.h"

using namespace std;

ComputerPresenter::ComputerPresenter(Computer& pc, ConsoleView& view) : pc(pc), view(view){}

void ComputerPresenter::run()
{
	bool running = true;
	while (running)
	{
		view.showMainMenu();
		int choice = view.getMainMenuChoice();

		switch (choice)
		{
		case 1: changeComputer(); break;
		case 2: view.showMessage("Not available right now, sorry!"); break;
		case 3: checkBuildState(); break;
		case 4: showComputer(); break;
		case 5: showComponent(); break;
		case 6: cleanComputer(); break;
		case 0: running = false; break;
		default: view.showMessage("Incorrect enter."); break;
		}
	}
}

//methods
void ComputerPresenter::changeComputer()
{
	bool editing = true;
	while (editing)
	{
		view.showComputerEditMenu();
		int choice = view.getComputerEditChoice();

		switch (choice)
		{
		case 1:
		{
			CPUInputData data = view.inputCPUData();
			CPU cpu(data.model, data.cores, data.frequency, data.socket);
			if (ComputerValidator::isValidCPU(cpu))
			{
				pc.setCPU(cpu);
				view.showMessage("CPU has been installed!");
			}
			else
				view.showMessage("Incorrect enter!");
			break;
		}
		case 2:
		{
			GPUInputData data1 = view.inputGPUData();
			GPU gpu(data1.model, data1.memorySize, data1.powerConsumption);
			if (ComputerValidator::isValidGPU(gpu))
			{
				pc.setGPU(gpu);
				view.showMessage("GPU has been installed!");
			}
			else
				view.showMessage("Incorrect enter!");
			break;
		}
		case 3:
		{
			RAMInputData data2 = view.inputRAMData();
			RAM ram(data2.capacity, data2.type, data2.frequency);
			if (ComputerValidator::isValidRAMModule(ram))
			{
				pc.addRAM(ram);
				view.showMessage("RAM module has been installed!");
			}
			else
				view.showMessage("Incorrect enter!");
			break;
		}
		case 4:
		{
			StorageInputData data3 = view.inputStorageData();
			Storage storage(data3.capacity, data3.type, data3.readSpeed);
			if (ComputerValidator::isValidStorage(storage))
			{
				pc.setStorage(storage);
				view.showMessage("Storage has been installed!");
			}
			else
				view.showMessage("Incorrect enter!");
			break;
		}
		case 5:
		{
			PowerSupplyInputData data4 = view.inputPowerSupplyData();
			PowerSupply power_supply(data4.wattage, data4.certificate);
			if (ComputerValidator::isValidPowerSupply(power_supply))
			{
				pc.setPowerSupply(power_supply);
				view.showMessage("Power supply has been installed!");
			}
			else
				view.showMessage("Incorrect enter!");
			break;
		}
		case 6:
		{
			MotherboardInputData data5 = view.inputMotherboardData();
			Motherboard motherboard(data5.model, data5.chipset, data5.formFactor, data5.socket, data5.typeOfRAM);
			if (ComputerValidator::isValidMotherboard(motherboard))
			{
				pc.setMotherboard(motherboard);
				view.showMessage("Motherboard has been installed!");
			}
			else
				view.showMessage("Incorrect enter!");
			break;
		}
		case 0:
		{
			editing = false;
			break;
		}
		default:
			view.showMessage("Incorrect choice.");
			break;
		}
	}
}
void ComputerPresenter::cleanComputer()
{

}
void ComputerPresenter::showComputer()
{

}
void ComputerPresenter::showComponent()
{

}
void ComputerPresenter::checkBuildState()
{

}