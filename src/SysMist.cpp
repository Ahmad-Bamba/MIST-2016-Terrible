#include "../Headers/SysMist.h"


SysMist::SysMist(){

}
SysMist::~SysMist();

//In your program. This function needs to be run first!

void SysMist::setOS(){
	#ifdef _WIN32
	Mist::currentOS = Mist::WIN32;
	#elif _WIN64
	Mist::currentOS = Mist::WIN64;
	#elif __unix || __unix__
	Mist::currentOS = Mist::UNIX;
	#elif __APPLE__ || __MACH__
	Mist::currentOS = Mist::MACOSX;
	#elif __linux__
	Mist::currentOS = Mist::LINUX;
	#else
	Mist::currentOS = Mist::OTHER;
	#endif
}

Mist::OS SysMist::getOS(){
	return currentOS;
}
