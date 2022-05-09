#pragma once
#include "Book.h"
#include "User.h"
#include "MyVector.hpp"
#include "KeyValuePair.hpp"

class Kindle
{
	MyVector<KeyValuePair<int>> titleToId;
	MyVector<User> users;
	MyVector<Book> library;

	void loadUsers();
	void loadBooks();

	bool userExists(const char* username, const char* password);
public:
	Kindle();

	bool registrate(const char* username, const char* password);
	User* login(const char* username, const char* password);
	const MyVector<Book>& getAllBooks() const;
	int findIdByName(const char* name) const;
	void rate(const char* username, const char* title, double rating);
	const MyVector<Rate>* getRatesForBook(const char* title) const;
	const MyVector<Comment>* getCommentsForBook(const char* title) const;
	void addBook(Book& book);
	void comment(const char* username, const char* title, const char* comment);
	Book& getBookByTitle(const char* title);

	void saveBooks() const;
	void saveUsers() const;
};