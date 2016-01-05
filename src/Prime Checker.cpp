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

void PrimeCheck::checkFull(uint64_t number)
{
	std::thread t1(&PrimeCheck::checkFirstHalf, this, number);
	std::thread t2(&PrimeCheck::checkSecondHalf, this, number);

	t1.join();
	t2.join();
}

void PrimeCheck::checkFirstHalf(uint64_t number)
{
	printf("Called checkFirstHalf()\n");

	bool numberIsPrime1;
	numberIsPrime1 = true;

	while(check < number/2 && numberIsPrime1 == true)
	{
		//printf("(1) Checking with %lli \n", check);

		if(number % check == 0){
			numberIsPrime1 = false;
		}
		else{
			numberIsPrime1 = true;
		}
		check++;

	}

	primebits.push_back(numberIsPrime1); //report the results
	printf("checkFirstHalf(): Pushed value to numberIsPrime.\n");
}

void PrimeCheck::checkSecondHalf(uint64_t number)
{
	printf("Called checkSecondHalf()\n");

	bool numberIsPrime2;
	numberIsPrime2 = true;
	check2 = number/2; //start at half

	while(check2 < number && numberIsPrime2 == true)
	{
		//printf("(2) Checking with %lli \n", check2);
		if(number % check2 == 0){
			numberIsPrime2 = false;
		}
		else{
			numberIsPrime2 = true;
		}
		check2++;
	}

	primebits.push_back(numberIsPrime2); //report the results
	printf("checkSecondHalf(): Pushed value to numberIsPrime.\n");
}

bool PrimeCheck::checkPrimeTheEasyWay(uint64_t number)
{
	return true;
}

//comment
