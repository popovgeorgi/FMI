#pragma once
#include "Book.h"
#include "MyVector.hpp"

class User
{
	char username[25];
	char password[30];
	MyVector<int> readBooks;
	MyVector<int> writtenBooks;

public:
	User();
	User(const char* username, const char* password);

	void addToReadCollection(int id);
	void addToWroteCollection(int id);
	bool setUsername(const char* username);
	bool setPassword(const char* password);

	const char* getUsername() const;
	const char* getPassword() const;
	int getReadBooksCount() const;
	int getWrittenBooksCount() const;
	bool read(int id);
	bool isAuthor(int id) const;
	bool hasRead(int id) const;

	const MyVector<int>& getReadBooks() const;
	const MyVector<int>& getWrittenBooks() const;
};

