#include <fstream>
#include <iostream>
#include "MyFile.h"
#include "Helpers.h"

using namespace std;

MyFile::MyFile(int bytesCount, char* fileName)
{
	initialFileName = fileName;
	bytes = new int[bytesCount];
	this->bytesCount = bytesCount;
	setBytes(fileName, bytesCount);
}

bool MyFile::replaceByte(int position, int newValue)
{
	if ((newValue < 0 || newValue > 255) || (position < 0 || position > bytesCount - 1))
	{
		return false;
	}
	bytes[position] = newValue;

	return true;
}

void MyFile::removeLastByte()
{
	bytesCount--;
	int* newBytes = new int[bytesCount];
	for (size_t i = 0; i < bytesCount; i++)
	{
		newBytes[i] = bytes[i];
	}
	delete[] bytes;
	bytes = newBytes;
}

bool MyFile::addByteAtTheEnd(int value)
{
	if (value < 0 || value > 255)
	{
		return false;
	}
	bytesCount++;
	int* newBytes = new int[bytesCount];
	for (size_t i = 0; i < bytesCount; i++)
	{
		newBytes[i] = bytes[i];
	}
	newBytes[bytesCount - 1] = value;
	delete[] bytes;
	bytes = newBytes;

	return true;
}

void MyFile::save()
{
	ofstream outFile(initialFileName, ios::trunc | ios::binary);
	if (!outFile)
	{
		return;
	}

	for (size_t i = 0; i < bytesCount; i++)
	{
		int byte = bytes[i];
		outFile.write((char*)&byte, 1);
	}
}

void MyFile::saveAs(char* fileName)
{
	ofstream outFile(fileName, ios::binary);
	if (!outFile)
	{
		return;
	}

	for (size_t i = 0; i < bytesCount; i++)
	{
		int byte = bytes[i];
		outFile.write((char*)&byte, 1);
	}
}

void MyFile::printBytesAsHex()
{
	for (size_t i = 0; i < bytesCount; i++)
	{
		int byte = bytes[i];
		cout << getHexFromDecimal(byte) << " ";
	}

	cout << endl;
}

void MyFile::printBytesAsSymbols()
{
	for (size_t i = 0; i < bytesCount; i++)
	{
		int byte = bytes[i];
		if ((byte >= 65 && byte <= 90) || (byte >= 97 && byte <= 122))
		{
			cout << (char)byte;
		}
		else
		{
			cout << ".";
		}
	}

	cout << endl;
}

void MyFile::setBytes(char* fileName, int fileSize)
{
	ifstream file(fileName, ios::binary);
	if (!file)
	{
		cout << "File could not be loaded!" << endl; 
		return;
	}

	cout << "File loaded successfully! Size: " << fileSize << " bytes" << endl;

	char byte;
	for (size_t i = 0; i < fileSize; i++)
	{
		file.get(byte);
		this->bytes[i] = (int)byte;
	}

	file.close();
}