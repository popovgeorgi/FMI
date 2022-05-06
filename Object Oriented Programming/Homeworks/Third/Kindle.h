#pragma once
#include "Book.h"
#include "User.h"
#include "MyVector.hpp"
#include "KeyValuePair.hpp"

class Kindle
{
	myVector<KeyValuePair<int, const char*>> idToTitle;
	myVector<KeyValuePair<const char*, int>> titleToId;
	myVector<User> users;
	myVector<Book> library;

	void loadUsers();
	void loadBooks();

	bool userExists(const char* username, const char* password);
public:
	Kindle();

	bool registrate(const char* username, const char* password);
	User* login(const char* username, const char* password);
	const myVector<Book>& getAllBooks() const;
	int findIdByName(const char* name) const;
	void rate(const char* username, const char* title, double rating);
	const myVector<Rate>& getRatesForBook(const char* title) const;
};