#ifndef TASK_HEADERS_MIST_H_
#define TASK_HEADERS_MIST_H_

#include "Mist.h"
#include "Encrypt.h"
//#include "PrimeChecker.h"
#include <string>

class Task
{
	friend class Mist;
public:
	Task(std::string tn, /*int am, int thr, std::vector<std::string> rps, */Mist::TaskInstruction ti); //std::string taskname, int allocatedMemory, int threads, std::vector<std::string> resourcePaths
	~Task();
	std::string getTaskName();

	Mist::TaskInstruction getTaskInstruction();
	int getAllocatedMemory(); //amount of RAM needed for task
	int getThreadNumber();
	std::vector<std::string> getResourcePaths();

	void start();

private:
	std::string Task_Name;
	int Allocated_Memory;
	int Threads;
	Mist::TaskInstruction Task_Instruction;
	std::vector<std::string> Resource_Paths;
	Encrypt* encrypt;
	//CheckPrimeTheHardWay* checkprime;
};

#endif
