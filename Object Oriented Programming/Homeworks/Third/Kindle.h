#pragma once
#include "Book.h"
#include "User.h"
#include "myVector.hpp"

class Kindle
{
	myVector<User> users;
	myVector<Book> library;

public:
	Kindle();

	bool registrate(const char* username, const char* password);
	User& login(const char* username, const char* password);
	const Book* getAllBooks() const;
};