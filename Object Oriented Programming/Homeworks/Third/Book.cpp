#include "Book.h"
#include <cstring>

#pragma warning(disable : 4996)

int Book::getId() const
{
	return id;
}

const char* Book::getTitle() const
{
	return title;
}

const char* Book::getAuthor() const
{
	return author;
}

void Book::addPage(Page page)
{
	pages.insert(page);
}

bool Book::setTitle(const char* title)
{
	//validation
	strcpy(this->title, title);

	return true;
}

bool Book::setAuthor(const char* author)
{
	//validation
	strcpy(this->author, author);

	return true;
}

bool Book::setRating(const char* username, double rating)
{
	//validate
	Rate rate(username, rating);
	rates.insert(rate);

	return true;
}

const myVector<Rate>& Book::getRatings() const
{
	return rates;
}