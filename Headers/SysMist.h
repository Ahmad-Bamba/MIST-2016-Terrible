#ifndef MISTINIT_HEADERS_SYSMIST_H_
#define MISTINIT_HEADERS_SYSMIST_H_

#include "Mist.h"

class SysMist: Mist{

private:
	SysMist();
	~SysMist();
public:
	void setOS();
	Mist::OS getOS();
};

#endif
