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
	MyString(const char* string);
	MyString(const MyString& other);
	~MyString();

	const MyString& operator=(const MyString& other);
	const MyString& operator+(const MyString& other);
	char& operator[](int index);
	friend const ostream& operator<<(ostream& stream, const MyString& object);
};

const MyString& MyString::operator+(const MyString& other)
{
	MyString copy = this->string;
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
	delete[] string;
}

