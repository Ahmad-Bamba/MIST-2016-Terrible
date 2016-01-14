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

void PrimeCheck::checkSecondHalf(uint64_t number)
{
	std::cout << "Called checkSecondHalf()" << std::endl;

	bool numberIsPrime2;
	numberIsPrime2 = true;
	uint64_t check2 = number/2;

	while(check2 < number && numberIsPrime2 == true)
	{
		if(number % check2 == 0){
			numberIsPrime2 = false;
		}
		else{
			numberIsPrime2 = true;
		}
		check2++;

	}

	if(numberIsPrime2)
		std::cout << "PrimeCheck returned prime" << std::endl;
	else
		std::cout << "Not prime!" << std::endl;
}

bool PrimeCheck::checkPrimeTheEasyWay(long long int number)
{
	return true;
}

//comment
