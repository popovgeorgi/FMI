#pragma once
#include "Book.h"
#include "MyVector.hpp"

class User
{
	char username[25];
	char password[30];
	myVector<int> read;
	myVector<int> written;

public:
	User();

	void addToReadCollection(int id);
	void addToWroteCollection(int id);
	bool setUsername(const char* username);
	bool setPassword(const char* password);

	const char* getUsername() const;
	bool read(const char* title);
	bool rate(const char* title);
	void write(const char* title, int pageCount);
	void addPage(const char* content);
};

