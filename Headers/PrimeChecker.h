#include <stdio.h>
#include <thread>
#include <vector>

class PrimeCheck
{
public:
	uint64_t numberToCheck;
	uint64_t check = 2;
	uint64_t check2;

	void checkFirstHalf(uint64_t number);
	void checkSecondHalf(uint64_t number);
	void checkFull(uint64_t number);
	bool checkPrimeTheEasyWay(uint64_t number);

	std::vector<bool> primebits;
private:

};

//comment
