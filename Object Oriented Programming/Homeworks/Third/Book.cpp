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

bool Book::addComment(const char* username, const char* comment)
{
	//validate
	Comment newComment(username, comment);
	comments.insert(newComment);

	return true;
}

bool Book::setRating(const char* username, double rating)
{
	//validate
	Rate rate(username, rating);
	rates.insert(rate);

	return true;
}

const MyVector<Rate>& Book::getRatings() const
{
	return rates;
}

bool Book::setId(int id)
{
	//validate
	this->id = id;

	return true;
}

const MyVector<Page>& Book::getPages() const
{
	return pages;
}

int Book::getPagesCount() const
{
	return pages.getSize();
}

int Book::getCommentsCount() const
{
	return comments.getSize();
}

int Book::getRatesCount() const
{
	return rates.getSize();
}

const MyVector<Comment>& Book::getComments() const
{
	return comments;
}