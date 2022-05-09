#include "User.h"
#include <cstring>

#pragma warning(disable : 4996)

User::User()
{

}

User::User(const char* username, const char* password)
{
	strcpy(this->username, username);
	strcpy(this->password, password);
}

bool User::setUsername(const char* username)
{
	//validation
	strcpy(this->username, username);

	return true;
}
bool User::setPassword(const char* password)
{
	//validation
	strcpy(this->password, password);

	return true;
}

const char* User::getUsername() const
{
	return username;
}
bool User::read(int id)
{
	//validate
	readBooks.insert(id);

	return true;
}

void User::addToReadCollection(int id)
{
	readBooks.insert(id);
}

void User::addToWroteCollection(int id)
{
	writtenBooks.insert(id);
}

const char* User::getPassword() const
{
	return password;
}

bool User::isAuthor(int id) const
{
	int writtenBooksCount = writtenBooks.getSize();
	for (size_t i = 0; i < writtenBooksCount; i++)
	{
		if (writtenBooks[i] == id)
		{
			return true;
		}
	}

	return false;
}

bool User::hasRead(int id) const
{
	int readBooksCount = readBooks.getSize();
	for (size_t i = 0; i < readBooksCount; i++)
	{
		if (readBooks[i] == id)
		{
			return true;
		}
	}

	return false;
}

int User::getReadBooksCount() const
{
	return readBooks.getSize();
}

int User::getWrittenBooksCount() const
{
	return writtenBooks.getSize();
}

const MyVector<int>& User::getReadBooks() const
{
	return readBooks;
}

const MyVector<int>& User::getWrittenBooks() const
{
	return writtenBooks;
}