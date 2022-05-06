#include "User.h"
#include <cstring>

#pragma warning(disable : 4996)

User::User()
{

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
void User::write(const char* title, int pageCount)
{

}
void User::addPage(const char* content)
{

}

void User::addToReadCollection(int id)
{

}

void User::addToWroteCollection(int id)
{

}

const char* User::getPassword() const
{
	return password;
}