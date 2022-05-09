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
	MyVector<Page> pages;
	MyVector<Comment> comments;
	MyVector<Rate> rates;

public:
	int getId() const;
	const char* getTitle() const;
	const char* getAuthor() const;

	void addPage(Page page);
	bool setTitle(const char* title);
	bool setAuthor(const char* author);
	bool setRating(const char* username, double rating);
	bool setId(int id);
	bool addComment(const char* username, const char* comment);

	int getPagesCount() const;
	int getCommentsCount() const;
	int getRatesCount() const;

	const MyVector<Page>& getPages() const;
	const MyVector<Comment>& getComments() const;
	const MyVector<Rate>& getRatings() const;
};