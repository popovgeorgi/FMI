#include "WordCollection.h"

WordCollection& WordCollection::operator*=(const char* word)
{
	data.insert(word);
	return *this;
}

bool WordCollection::operator[](const char* word)
{
	if (data.searchTree(word) == nullptr)
	{
		return false;
	}

	return true;
}