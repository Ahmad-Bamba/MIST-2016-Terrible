/*
 * Mist.h
 *
 *  Created on: Nov 12, 2015
 *      Author: david
 */
#ifndef MISTINIT_HEADERS_MIST_H_
#define MISTINIT_HEADERS_MIST_H_

#include <string>
#include <vector>

//TODO: Fatal error! Fix ASAP! MachineOS string is bothersome.
//Lumpy clumpy clods!
//std::string MachineOS; //global variable fml

#ifdef _WIN32
   std::string MachineOS = "Windows32";
   #ifdef _WIN64
      MachineOS = "Windows64";
   #endif
#elif __APPLE__
    #include "TargetConditionals.h"
    #if TARGET_IPHONE_SIMULATOR
         #error "Unsupported _APPLE_ device, TARGET_IPHONE_SIMULATOR"
    #elif TARGET_OS_IPHONE
		 #error "Unsupported _APPLE_ device, TARGET_OS_IPHONE"
    #elif TARGET_OS_MAC
         std::string MachineOS = "MacOSX"
    #else
    #   error "Unknown _APPLE_ platform"
    #endif
#elif __linux__
    std::string MachineOS = "Linux";
#elif __unix__ // all unices not caught above
	#error "_unix_ devices are not supported by this library!"
#elif defined(_POSIX_VERSION)
	#error "_POSIX_ devices are not supported by this library!"
#else
#   error "Unknown compiler"
#endif

class Mist
{
public:
	//VARS
		//TYPES
			enum OS{WINDOWS, DEBIANLINUX, MACOSX, FEDORALINUX, OTHER};
			enum InitInstruction{CREATETHREAD, ALLOCATERAM, GETSYSINFO};
			enum TaskInstruction{START, PAUSE, STOP, WAIT};
			enum ProcessorType{AMD64, i386};
		//STRUCTS
			struct Machine
			{
				std::string IP;
				int allocatedMemory; //Amount of memory allocated to the machine
				int threads; //Amount of threads Machine is running
				std::string MachineName = "DefaultMachineName"; //Name of Machine
				OS MachineOS; //Machine OS
				int ping; //Latest ping to machine in ms, measured by the second
				int averagePing; //Average ping over last 15 seconds
				std::string OSName; //Version # (i.e. Windows 7), used to identify OTHER
				bool MachineIsMaster;
			};

			struct task
			{
				std::string name; //name of task
				int allocatedMemory; //memory in megabytes allocated to task
				int threads; //threads allocated to task
				int machineIDs; //machines running on
				std::vector<std::string> resourcePaths; //folders where resources files are, to be compressed and transported, (maybe encrypted)
				std::vector<std::string> parallelTasks; //names of tasks running in parallel
			};

			struct TaskGroup
			{
				std::vector<task> tasksInGroup; //collection of tasks in group
			};
		//VECTORS
			std::vector<Machine> Machines;
			std::vector<task> Task; //individual Task
		//INT
			static int maximumThreadsToSystem; //maximum threads that can run
			static int maximumAllocatedMemory; //maximum amount of memory allowed to be used

			static int memoryAllocatedToMachine; //threads allocated to this machine
			static int threadsAllocatedToMachine; //threads allocated to this machine

			static int masterMachineID; //position of master machine in memory
		//BOOL
			static bool machineIsMaster; //is this machine master?

	//FUNCTIONS
		//INIT
			Mist(int computersInArray, int maxAllocatedRAM, int totalThreads, std::vector<std::string> IPs); //constructs system in memory, assigns max memory and threads to each according to their abilities
			~Mist();
			void InitInstruct(int MachineID, InitInstruction intruction, int param); //sends instruction type with a parameter
			void AddComputerToArray(std::string IP, OS operatingSystem, int allocatedMemory, int threads); //Adds memory and threads to maximum allocated threads/memory
			void CreateTask(std::string taskname, int allocatedMemory, int threads, std::vector<std::string> resourcePaths); //creates task
			void CreateTaskGroup(std::string taskGroup, std::string taskname, int allocatedMemory, int threads, std::vector<std::string> resourcePaths); //creates task in taskGroup
			void AddTaskToGroup(std::string taskname, std::string taskGroup); //adds premade task to task group
		//TASKPHASE
			void TaskInstruct(TaskInstruction instruction, std::string taskname); //Instructs machines in array to do things to task
			void TaskInstruct(TaskInstruction instruction, std::string taskGroupName, int tasksInGroup); //Instruct machines in array to do things to task group
			void BeginTask(std::string taskname);//Begins program after init, automatically reserves all resources allocated
			void BeginParallelCompute(std::string taskGroupName);//Begins new taskgroup, will not if new memory is more than max allocated memory
			void HeartBeat();//Called when task phase starts, checks for a response from each machine to ensure they are functioning, if master. Otherwise just checks if master is working
			void AssignCompute(int MachineID, int threadsRequired); //checks if there are enough threads to do operation and then does the operation

private:
		//INIT
			Machine GetSystemInfo(); //Gets OS, gets processor cores, gets memory of system and puts it into Machine struct

			void InitPeriodic(); //giant while loop does all of the following in Init
			void RecieveInitInstruction(); //Called periodically to check during init
		//TASKPHASE
			void StopCompute();//Pauses all tasks
			void StopCompute(std::string taskName); //searches for name, pauses that operation

			void DestroyTask(std::string taskName); //Checks if task is stopped, destroys task and all vars associated (ends using operating system)
			void DestroyTaskGroup(std::string taskGroupName); //Checks if task is stopped, destroys task and all vars associated (ends using operating system)

			void TaskPeriodic(); //giant while loop does all of the following in TaskPhase
			void RecieveTaskInstruction(); //recieves instructions from master machine
};
#endif /* MISTINIT_HEADERS_MIST_H_ */
