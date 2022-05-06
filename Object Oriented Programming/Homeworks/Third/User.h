#pragma once
#include "Book.h"
#include "MyVector.hpp"

class User
{
	char username[25];
	char password[30];
	myVector<int> readBooks;
	myVector<int> writtenBooks;

public:
	User();

	void addToReadCollection(int id);
	void addToWroteCollection(int id);
	bool setUsername(const char* username);
	bool setPassword(const char* password);

	const char* getUsername() const;
	const char* getPassword() const;
	bool read(int id);
	void write(const char* title, int pageCount);
	void addPage(const char* content);
};

