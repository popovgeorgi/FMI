#pragma once
#include "Book.h"

class User
{
	const char username[25];
	char password[30];
	Book* read;
	Book* written;

public:
	const char* getUsername();
	bool read(const char* title);
	bool rate(const char* title);
	void write(const char* title, int pageCount);
	void addPage(const char* content);
};

