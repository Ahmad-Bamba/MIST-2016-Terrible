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

void PrimeCheck::checkFull(long long int number)
{
	std::thread t1(&PrimeCheck::checkFirstHalf, this, number);
	std::thread t2(&PrimeCheck::checkSecondHalf, this, number);

	t1.join();
	t2.join();
}

void PrimeCheck::checkFirstHalf(long long int number)
{
	bool numberIsPrime = new bool;
	numberIsPrime = true;
	while(check < int(number/2) && numberIsPrime == true)
	{
		if(int(number/2) % check != 0)
		{

		}else if(int(number/2) % check == 0){
			numberIsPrime = false;
		}
		check++;
		//printf("Checking with %lli \n", check);
	}

	primebits.push_back(numberIsPrime); //report the results
}

void PrimeCheck::checkSecondHalf(long long int number)
{
	bool numberIsPrime = new bool;
	numberIsPrime = true;
	check2 = int(number/2); //start at half
	while(check2 < number && numberIsPrime == true)
	{
		if(number % check2 != 0)
		{

		}else if(number % check2 == 0){
			numberIsPrime = false;
		}
		check++;
		//printf("Checking with %lli \n", check);
	}

	primebits.push_back(numberIsPrime); //report the results
}

bool PrimeCheck::checkPrimeTheEasyWay(long long int number)
{
	return true;
}

//comment
