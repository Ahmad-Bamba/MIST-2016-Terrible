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
#include <cmath>

class Encrypt
{
public:
	Encrypt();
	~Encrypt();
	std::string EncryptFile(int sectorLength, int seed, int runs);
private:
	std::string EncryptString(std::string string);
};



#endif /* ENCRYPT_H_ */
