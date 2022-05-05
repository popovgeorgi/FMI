#include "User.h"
#include <cstring>

User::User()
{

}

bool User::setUsername(const char* username)
{
	//validation
	strcpy(this->username, username);
}
bool User::setPassword(const char* password)
{
	//validation
	strcpy(this->password, password);
}

const char* User::getUsername() const
{

}
bool User::read(const char* title) {}
bool User::rate(const char* title) 
{

}
void User::write(const char* title, int pageCount) {}
void User::addPage(const char* content) {}