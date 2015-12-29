//============================================================================
// Name        : Prime.cpp
// Author      : 
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "PrimeChecker.h"

int main() {
	PrimeCheck * checkers;
	checkers = new PrimeCheck();
	bool trueScienceFact;
	//checkers->check = 2;
	trueScienceFact = checkers->checkPrimeTheHardWay(10000019 /*Can be any prime*/);
	if(trueScienceFact)
	{
		printf("It's Prime!");
	}
	else if(!trueScienceFact)
	{
		printf("Not a prime...");
	}
}

bool PrimeCheck::checkPrimeTheHardWay(long long int number)
{
	bool numberIsPrime = new bool;
	numberIsPrime = true;
	while(check < number && numberIsPrime == true)
	{
		if(number % check != 0)
		{

		}else if(number % check == 0){
			numberIsPrime = false;
		}
		check++;
		printf("Checking with %i \n", check);
	}
	return numberIsPrime;
}

bool PrimeCheck::checkPrimeTheEasyWay(long long int number)
{
	return true;
}
