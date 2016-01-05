#include "../Headers/Mist.h"
#include "../Headers/SysMist.h"
#include "../Headers/Task.h"

int main(){
	printf("Hello world!\n");

	Mist* mist;
	SysMist* system= new SysMist();
	system->setOS();
	Task* task = new Task("Task 1", mist->PRIME_OPERATION);

	task->start();

	std::string Taskname = task->getTaskName();

	printf("%s is finished running", Taskname);
}
