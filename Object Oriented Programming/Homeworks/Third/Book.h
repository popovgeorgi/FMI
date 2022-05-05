#pragma once
#include "Page.h"
#include "MyVector.hpp"
#include "Comment.h"

class Book
{
	// read about utilizing the least amount of memory
	int id;
	char title[40];
	char author[30];
	double rating;
	myVector<Page> pages;
	myVector<Comment> comments;

public:
	void addPage(Page page);
	bool setTitle(const char* title);
	bool setAuthor(const char* author);
	bool setRating(double rating);
};