#ifndef MISTINIT_HEADERS_SYSMIST_H_
#define MISTINIT_HEADERS_SYSMIST_H_

#include "Mist.h"

class SysMist: Mist{

private:

public:
	SysMist();
	~SysMist();

	void setOS();
	Mist::OS getOS();

};

#endif
