#include "Helpers.h"
#include "MyString.h"

const char* getWordFromString(int wordIndex, const char* string)
{
	MyString word;
	int spaces = 0;

	int len = strlen(string);
	for (size_t i = 0; i < len; i++)
	{
		if (spaces == wordIndex)
		{
			for (size_t j = i; j < len; j++)
			{
				word += (const char*)string[j];

				if (string[i] == ' ')
				{
					return word.getString();
				}
			}

			return word.getString(); //edgecase
		}

		if (string[i] == ' ')
		{
			spaces++;
			continue;
		}
	}
}