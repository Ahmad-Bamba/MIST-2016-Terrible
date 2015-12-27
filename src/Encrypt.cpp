//============================================================================
// Name        : Encrypt.cpp
// Author      : 
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Encrypt.h"

using namespace std;

int main() {
	Encrypt * EncryptTest = new Encrypt;
	std::vector<int> print;
	print = EncryptTest->EncryptFile(7, 50, 512);
}

Encrypt::Encrypt()
{

}

Encrypt::~Encrypt()
{

}

std::vector<int> Encrypt::EncryptFile(int seed, int runs, int bits)
{
	bigNumber key = generateKey(bits);
	fstream fileToEncrypt;

	return key.number;
}


Encrypt::bigNumber Encrypt::generateKey(int length)
{
	bigNumber key;
	key.length = length; //sets length of return value in bits
	key.lengthInDigits = 2*log10(length) + 1;
	for(int i = 0; i < key.lengthInDigits; i++)
	{
		key.number[i] = rand()%10;
	}
	return key;
}

