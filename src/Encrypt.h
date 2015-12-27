/*
 * Encrypt.h
 *
 *  Created on: Nov 17, 2015
 *      Author: david
 */

#ifndef ENCRYPT_H_
#define ENCRYPT_H_

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <math.h>

class Encrypt
{
public:

	struct bigNumber
	{
		int length; //length in bits
		int lengthInDigits; //length in digits
		std::vector<int> number; //numbers in array
	};

	Encrypt();
	~Encrypt();
	std::vector<int> EncryptFile(int seed, int runs, int bits);
private:
	std::string EncryptString(std::string string);
	bigNumber generateKey(int length); //generates key, takes length in bits
};



#endif /* ENCRYPT_H_ */
