#pragma once
#include "Page.h"
#include "MyVector.hpp"
#include "Comment.h"
#include "Rate.h"

class Book
{
	// read about utilizing the least amount of memory
	int id;
	char title[40];
	char author[30];
	myVector<Page> pages;
	myVector<Comment> comments;
	myVector<Rate> rates;

public:
	int getId() const;
	const char* getTitle() const;
	const char* getAuthor() const;

	void addPage(Page page);
	bool setTitle(const char* title);
	bool setAuthor(const char* author);
	bool setRating(const char* username, double rating);

	const myVector<Rate>& getRatings() const;
};