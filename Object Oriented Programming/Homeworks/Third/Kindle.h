#pragma once
#include "Book.h"
#include "User.h"
#include "MyVector.hpp"
#include "KeyValuePair.hpp"

class Kindle
{
	myVector<KeyValuePair<int, char*>> idToTitle;
	myVector<KeyValuePair<char*, int>> titleToId;
	myVector<User> users;
	myVector<Book> library;

	void loadUsers();
	void loadBooks();
public:
	Kindle();

	bool registrate(const char* username, const char* password);
	User& login(const char* username, const char* password);
	const Book* getAllBooks() const;
};