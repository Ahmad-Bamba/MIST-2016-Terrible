//============================================================================
// Name        : Prime.cpp
// Author      : 
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "PrimeChecker.h"


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
	}
	return numberIsPrime;
}

bool PrimeCheck::checkPrimeTheEasyWay(long long int number)
{
	return true;
}

int main() {
	PrimeCheck * check;
	bool trueScienceFact;
	trueScienceFact = check->checkPrimeTheHardWay(184467440741);
	if(trueScienceFact)
	{
		printf("It's Prime!");
	}
}
