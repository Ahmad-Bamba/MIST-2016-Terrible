#include <stdio.h>
#include <thread>
#include <vector>

class PrimeCheck
{
public:
	long long int numberToCheck;
	long long int check = 2;
	long long int check2;

	void checkFirstHalf(long long int number);
	void checkSecondHalf(long long int number);
	void checkFull(long long int number);
	bool checkPrimeTheEasyWay(long long int number);

	std::vector<bool> primebits;
private:

};

//comment
