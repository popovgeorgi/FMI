// 3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>

const size_t MAX_RELATION_SIZE = 25;

struct pair {
	unsigned int x1;
	unsigned int x2;
};

struct pairCollection {
	pair data[MAX_RELATION_SIZE];
};

pair createPair(unsigned int x1, unsigned int x2) {
	pair newPair;
	newPair.x1 = x1;
	newPair.x2 = x2;

	return newPair;
}

void addPairToRelation(pair collection[], pair pair, int index) {
	collection[index] = pair;
}

bool writePairToFile(pair pair, const char* dest, bool isStart) {
	std::ofstream outFile(dest, std::ios::app);
	if (!outFile.is_open())
	{
		return false;
	}

	if (isStart)
	{
		outFile << "(" << pair.x1 << "," << pair.x2 << ")";
	}
	else 
	{
		 outFile << std::endl << "(" << pair.x1 << "," << pair.x2 << ")";
	}

	return true;
}

pair parsePairFromFile(char* str) {
	pair pair;

	int index = 1;
	int firstNum = 0;

	while (true)
	{
		if (str[index] == ',')
		{
			index++;
			break;
		}

		firstNum *= 10;
		firstNum += str[index++] - 48;
	}
	pair.x1 = firstNum;
	int secondNum = 0;
	while (true)
	{
		if (str[index] == ')')
		{
			break;
		}

		secondNum *= 10;
		secondNum += str[index++] - 48;
	}
	pair.x2 = secondNum;

	return pair;
}

int main()
{
	std::ifstream inFile("relations.txt");
	if (!inFile.is_open())
	{
		return -1;
	}

	pairCollection myCollection = pairCollection();

	int index = 0;
	bool start = true;
	if (inFile.peek() == EOF)
	{
		srand(time(NULL));

		for (size_t i = 0; i < MAX_RELATION_SIZE; i++)
		{
			if (rand() % 2 == 0)
			{
				pair newPair = createPair(rand(), rand());
				addPairToRelation(myCollection.data, newPair, index++);
				if (writePairToFile(newPair, "relations.txt", start) == false) return -1;
				start = false;
			}
		}
	}
	else
	{
		std::ifstream inFile("relations.txt");
		if (!inFile.is_open())
		{
			return -1;
		}

		while (!inFile.eof())
		{
			char buffer[1024];
			inFile.getline(buffer, 1024);
			pair pair = parsePairFromFile(buffer);
			myCollection.data[index++] = pair;
		}
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
