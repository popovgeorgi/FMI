#include <iostream>
#include <fstream>

using namespace std;

int getBytesOfFile(char* fileName)
{
	//optimize
	ifstream inFile(fileName, ios::binary);
	if (!inFile)
	{
		return -1;
	}

	size_t counter = 0;
	while (true)
	{
		inFile.get();
		if (inFile.eof())
		{
			break;
		}
		counter++;
	}

	return counter;
}

char getCharForInt(int n)
{
	if (n >= 0 && n <= 9)
	{
		return n + '0';
	}
	else
	{
		if (n == 10)
		{
			return 'A';
		}
		else if (n == 11)
		{
			return 'B';
		}
		else if (n == 12)
		{
			return 'C';
		}
		else if (n == 13)
		{
			return 'D';
		}
		else if (n == 14)
		{
			return 'E';
		}
		else if (n == 15)
		{
			return 'F';
		}
	}
}

char* getHexFromDecimal(int n)
{
	char* hex = new char[3];

	int remainer = n / 16;
	if (remainer == 0)
	{
		hex[0] = '0';
		remainer = n % 16;
	}
	else
	{
		hex[0] = getCharForInt(remainer);
		remainer = n - 16 * remainer;
	}

	if (remainer >= 0 || remainer <= 9)
	{
		hex[1] = getCharForInt(remainer);
	}
	else
	{
		hex[1] = getCharForInt(remainer);
	}
	hex[2] = '\0';

	return hex;
}



void printBytesFromFile(char* fileName)
	{
		ifstream inFile(fileName, ios::binary);
		if (!inFile)
		{
			return;
		}

		char byte;
		while (true)
		{
			inFile.get(byte);
			if (inFile.eof())
			{
				return;
			}

			cout << getHexFromDecimal(int(byte)) << " ";
		}
	}

void printTextFromFile(char* fileName)
	{
		ifstream inFile(fileName, ios::binary);
		if (!inFile)
		{
			return;
		}

		char byte;
		while (true)
		{
			inFile.get(byte);
			if (inFile.eof())
			{
				return;
			}

			if ((byte >= 65 && byte <= 90) || (byte >= 97 && byte <= 122))
			{
				cout << byte;
			}
			else
			{
				cout << '.';
			}
		}
	}

struct File
{
	int* bytes;
	int bytesCount;
	char* initialFileName;

	File(int bytesCount, char* fileName)
	{
		initialFileName = fileName;
		bytes = new int[bytesCount];
		this->bytesCount = bytesCount;
		setBytes(fileName, bytesCount);
	}

	void replaceByte(int position, int newValue)
	{
		bytes[position] = newValue;
	}

	void removeLastByte()
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

	void addByteAtTheEnd(int value)
	{
		//validate value to be a 0 - 255
		bytesCount++;
		int* newBytes = new int[bytesCount];
		for (size_t i = 0; i < bytesCount; i++)
		{
			newBytes[i] = bytes[i];
		}
		newBytes[bytesCount - 1] = value;
		delete[] bytes;
		bytes = newBytes;
	}

	void save()
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

	void saveAs(char* fileName)
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

	void printBytesAsHex()
	{
		for (size_t i = 0; i < bytesCount; i++)
		{
			int byte = bytes[i];
			cout << getHexFromDecimal(byte) << " ";
		}
	}

	void printBytesAsSymbols()
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
	}

private:
	void setBytes(char* fileName, int fileSize)
	{
		ifstream file(fileName, ios::binary);
		if (!file)
		{
			return;
		}

		char byte;
		for (size_t i = 0; i < fileSize; i++)
		{
			file.get(byte);
			this->bytes[i] = (int)byte;
		}

		file.close();
	}
};

int main()
{
	char input[50];
	cin.getline(input, 50);

	int bytesCount = getBytesOfFile(input);
	File myFile(bytesCount, input);
	myFile.addByteAtTheEnd(23);
	myFile.printBytesAsHex();
}
