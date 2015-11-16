//============================================================================
// Name        : MistInit.cpp
// Author      : 
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================
#include "../Headers/Mist.h"

int main() {
	return 0;
}

Mist::Mist(int computersInArray, int maxAllocatedRAM, int totalThreads, std::vector<std::string> IPs)
{
	//GENERATE MACHINE VECTOR
	//Machines.push_back();
	Machines[1].IP = "localhost:4900";
	Machines[1].MachineIsMaster = true;
	//TODO get machine information, assign memory, and
	for(computersInArray; computersInArray == 0; computersInArray--)
	{
		//Machines.push_back();
		Machines[computersInArray].IP = IPs[computersInArray];
	}

	//INSTRUCT OTHER MACHINES TO GENERATE MACHINE VECTOR

	//ASK FOR MISSING INFO AND BUILD OTHER MACHINE'S INFORMATION INDEX
		/* Cycle through vector, ask machines to send missing info in the form of a Machine struct
		 * Each time get info, then delete machine struct
		 * Assign each machine maximum memory
		 * Then give every other machine info to slave machine, wait for response, and move onto the next
		 */
	//SET ALLOCATED MEMORY GLOBAL VAR
}
