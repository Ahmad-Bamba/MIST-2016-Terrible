//============================================================================
// Name        : Encrypt.cpp
// Author      : 
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "../Headers/Encrypt.h"
//TODO why does this delete the file when it opens?

using namespace std;

int main() {
	Encrypt * EncryptTest = new Encrypt;
	EncryptTest->EncryptFile(5, 50, 100);
	/*std::string print;
	print.assign(EncryptTest->EncryptFile(5, 128, 5));
	ofstream outPut;
	outPut.open("text.txt");
	int outPutLength = print.length();
	outPut.close();*/
	return 0;
}

Encrypt::Encrypt()
{

}

Encrypt::~Encrypt()
{

}

std::string Encrypt::EncryptFile(int sectorLength, int seed, int runs)
{
  if(sectorLength < 180)
  {
	std::string fileOut;
	std::vector<char> encryptBuffer;
	std::fstream file;
	std::string Buf;
	//char * sectorBuffer = new char[sectorLength];
	file.open("test.txt", ios_base::app | ios_base::binary | ios_base::in | ios_base::out);
	file.seekg(0, file.end);
	int length = file.tellg();
	cout << length << endl;
	//TODO fix this so it reads chars right, needs null terminator
	char * fileBuf =  new char [length+1];
	int it;
	file.read(fileBuf, length);
	Buf = fileBuf;
	int cyclesRun = 0;
	//int charsInBuffer;
	std::string sectorBuffer;
	long int charsEncrypted = 0;
	char * cstr = new char[sectorLength+1];
	int charTransfer;
	int previousChar;
	if(file.is_open())
	{
		int ran;
		while(cyclesRun < runs)
		{
			/*while(charsEncrypted < length)
			{
				file.read(sectorBuffer, sectorLength);
				while(iterator < sectorLength)
				{
					sectorBuffer[iterator] = std::abs(sectorBuffer[iterator] - sectorBuffer[iterator-1]) + pow(seed, -1);
					iterator++;
					cout << "Read " << iterator << " sectors so far..." << endl;
				}
				iterator = 0;
				while (iterator < sectorLength)
				{
					charTransfer = sectorBuffer[iterator];
					fileOut.push_back(charTransfer);
					iterator++;
				}
				charsEncrypted = charsEncrypted + sectorLength;
				cout << "Read " << charsEncrypted << " characters so far..." << endl;
				encryptBuffer.resize(0);
			}*/
			while(charsEncrypted < length)
			{
				sectorBuffer.reserve(sectorLength); //reserves space for the buffer to be written to
				sectorBuffer.assign(Buf.substr(cyclesRun*sectorLength, sectorLength)); //writes sector to the buffer
				//cstr = sectorBuffer.c_str();
				std::strcpy(cstr, sectorBuffer.c_str()); //puts sectorBuffer into cstr[]
				sectorBuffer.clear();//clears sectorBuffer
				for(int iterator = 0; iterator+1 < sectorLength; iterator++)
				{
					ran = rand()%255;
					charTransfer = cstr[iterator];
					charTransfer = charTransfer - 48;
					if(iterator > 1)
					{
						previousChar = cstr[iterator-1];
						previousChar = previousChar - 48;
					}else{
						previousChar = sectorLength;
					}
					charTransfer = std::abs(std::abs(charTransfer - previousChar) + pow(seed, -1))/ran;
					charTransfer = charTransfer + 48;
					sectorBuffer.push_back(charTransfer);
				}
				fileOut.append(sectorBuffer); //fileOut = fileOut + sectorBuffer;
				sectorBuffer.clear(); //frees up that memory
				charsEncrypted = charsEncrypted + sectorLength; //counts chars encrypted
				cout << charsEncrypted << " characters read" << endl; //prints out the amount of characters read
			}
			Buf.assign(fileOut);//assigns Buf fileOut's data
			cyclesRun++; //breaks loop
			std::cout << "Cycles run: " << cyclesRun << endl; //prints cycle data
			if(cyclesRun < runs)
			{
				fileOut.clear(); //clears fileOut on all but the last run
			}
		}
		cout << "writing to file..." << endl;
		file << Buf;
		cout << "done writing to file..." << endl;
		file.close();
	}else if(!file.is_open()){
		printf("File didn't open! Idk why! \n");
	}
	return fileOut;
	}else{
		printf("Error! Sector length cannot exceed 180! \n");
		return NULL;
  }
}


