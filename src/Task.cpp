#include "../Headers/Task.h"
#include <iostream>
#include <cstdlib>

Task::Task(std::string tn, /*int am, int thr, std::vector<std::string> rps, */Mist::TaskInstruction ti)
{
	encrypt = new Encrypt();
	//checkprime = new CheckPrimeTheHardWay();
	Task_Name        = tn;
	//Allocated_Memory = am;
	//Threads          = thr;
	//Resource_Paths   = rps;
	Task_Instruction = ti;
}

std::string Task::getTaskName()
{
	return Task_Name;
}

Mist::TaskInstruction Task::getTaskInstruction()
{
	return Task_Instruction;
}

int Task::getAllocatedMemory()
{
	return Allocated_Memory;
}

int Task::getThreadNumber()
{
	return Threads;
}

std::vector<std::string> Task::getResourcePaths()
{
	return Resource_Paths;
}

void Task::start() //when this is finished, call deconstructor and remove task. We can only do one file at a time.
{
	if (this->Task_Instruction == Mist::FILE_TRANSFER)
	{
		std::cout << "Starting file transfer...\n";
	}
	else if (this->Task_Instruction == Mist::DECRYPT)
	{
		std::cout << "Starting file decryption sequence...\n";
	}
	else if (this->Task_Instruction == Mist::ENCRYPT)
	{
		std::cout << "Starting encryption sequence...\n";
		encrypt->EncryptFile(1,1,1); // Example. We can pass down values while running.
	}
	else if (this->Task_Instruction == Mist::PAUSE)
	{
		std::cout << "Paused...\n";
	}
	else if (this->Task_Instruction == Mist::STOP)
	{
		std::cout << "Operation stopped!\n";
	}
	else if (this->Task_Instruction == Mist::WAIT)
	{
		std::cout << "Waiting to continue...\n";
	}
	else if (this->Task_Instruction == Mist::PRIME_OPERATION)
	{
		std::cout << "Beginning prime operation.";
		//checkprime->run //or something like that!
	}
	else
	{
		std::cout << "FATAL ERROR!!!!\n";
		//cleanup unnecessary objects!
		std::exit(0);
	}
}
