#pragma once
#pragma warning(disable : 4996)

#include <iostream>

using namespace std;

class MyString
{
	char* string;
	void copyFrom(const MyString& other);
	void free();

public:
	MyString();
	MyString(const char* string);
	MyString(const MyString& other);
	MyString(MyString&& other);
	~MyString();

	const MyString& operator=(const MyString& other);
	void operator=(MyString&& other);
	char& operator[](int index);
	MyString& operator+=(const MyString& other);

	void concat(const MyString& other);
	char* getString() const;
	friend const ostream& operator<<(ostream& stream, const MyString& object);
};

MyString operator+(const MyString& lhs, const MyString rhs);


