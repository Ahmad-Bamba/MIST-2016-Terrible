//============================================================================
// Name        : Prime.cpp
// Author      : 
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "../Headers/PrimeChecker.h"

/*int main() {
	PrimeCheck * checkers;
	checkers = new PrimeCheck();
	bool trueScienceFact;
	//checkers->check = 2;
	trueScienceFact = checkers->checkPrimeTheHardWay(10000019 Can be any prime);
	if(trueScienceFact)
	{
		printf("It's Prime!");
	}
	else if(!trueScienceFact)
	{
		printf("Not a prime...");
	}
}*/

void PrimeCheck::checkFirstHalf(uint64_t number)
{
	std::cout << "Called checkFirstHalf()" << std::endl;

	bool numberIsPrime1;
	numberIsPrime1 = true;
	uint64_t check = 2;

	while(check < number/2 && numberIsPrime1 == true)
	{

		if(number % check == 0){
			numberIsPrime1 = false;
		}
		else{
			numberIsPrime1 = true;
		}
		check++;

	}

	if(numberIsPrime1)
		std::cout << "Primecheck 1 returned true!\n";
	else
		std::cout << "Not a prime!\n";
}

bool PrimeCheck::checkPrimeTheEasyWay(long long int number)
{
	return true;
}

//comment
