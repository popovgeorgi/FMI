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

MyString operator+(const MyString& lhs, const MyString& rhs);

MyString operator+(const MyString& lhs, const MyString& rhs)
{
	MyString copyOfLeft(lhs);
	copyOfLeft += rhs;
	return copyOfLeft;
}

MyString& MyString::operator+=(const MyString& other)
{
	concat(other);
	return *this;
}

void MyString::concat(const MyString& other)
{
	int myLength = strlen(this->string);
	int otherLength = strlen(other.string);
	char* temp = new char[myLength + otherLength + 1];
	strcpy(temp, string);
	strcat(temp, other.string);

	delete[] string;
	string = temp;
}

MyString::MyString()
{
	string = new char[1];
	string[0] = '\0';
}

char* MyString::getString() const { return string; }

void MyString::operator=(MyString&& other)
{
	string = other.string;
	other.string = nullptr;
}

MyString::MyString(MyString&& other)
{
	string = other.string;
	other.string = nullptr;
}

const ostream& operator<<(ostream& stream, const MyString& object)
{
	stream << object.string;
	return stream;
}

char& MyString::operator[](int index)
{
	return string[index];
}

MyString::MyString(const char* string)
{
	this->string = new char[strlen(string) + 1];
	strcpy(this->string, string);
}

MyString::MyString(const MyString& other)
{
	copyFrom(other);
}

const MyString& MyString::operator=(const MyString& other)
{
	if (strcmp(this->string, other.string) != 0)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

void MyString::copyFrom(const MyString& other)
{
	this->string = new char[strlen(other.string) + 1];
	strcpy(this->string, other.string);
}

void MyString::free()
{
	delete[] string;
}

MyString::~MyString()
{
	free();
}

