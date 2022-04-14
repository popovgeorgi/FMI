#pragma once
#include "AVLTree.h"

class WordCollection
{
	AVLTree data;

public:
	WordCollection& operator*=(const char* word);
	bool operator[](const char* word);
};