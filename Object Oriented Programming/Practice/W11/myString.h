#pragma once
#pragma warning(disable : 4996)

#include <iostream>

using namespace std;

class myString
{
	char* string;
	void copyFrom(const myString& other);
	void free();

public:
	myString(const char* string);
	myString(const myString& other);
	~myString();

	const myString& operator=(const myString& other);
	const myString& operator+(const myString& other);
	char& operator[](int index);
	friend const ostream& operator<<(ostream& stream, const myString& object);
};

const myString& myString::operator+(const myString& other)
{
	myString copy = this->string;
	int myLength = strlen(this->string);
	int otherLength = strlen(other.string);
	free();
	this->string = new char[myLength + otherLength + 1];

	for (size_t i = 0; i < myLength; i++)
	{
		this->string[i] = copy[i];
	}
	for (size_t i = myLength; i < otherLength + myLength; i++)
	{
		this->string[i] = other.string[i - myLength];
	}
	this->string[myLength + otherLength] = '\0';
	cout << &this->string << endl;

	return *this;
}

const ostream& operator<<(ostream& stream, const myString& object)
{
	stream << object.string;
	return stream;
}

char& myString::operator[](int index)
{
	return string[index];
}

myString::myString(const char* string)
{
	this->string = new char[strlen(string) + 1];
	strcpy(this->string, string);
}

myString::myString(const myString& other)
{
	copyFrom(other);
}

const myString& myString::operator=(const myString& other)
{
	if (strcmp(this->string, other.string) != 0)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

void myString::copyFrom(const myString& other)
{
	this->string = new char[strlen(other.string) + 1];
	strcpy(this->string, other.string);
}

void myString::free()
{
	delete[] string;
}

myString::~myString()
{
	delete[] string;
}

