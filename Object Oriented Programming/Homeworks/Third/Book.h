#pragma once
#include "Page.h"

class Book
{
	// read about utilizing the least amount of memory
	const char title[40];
	const char author[30];
	int rating;
	Page* pages;
	char** comments;
};