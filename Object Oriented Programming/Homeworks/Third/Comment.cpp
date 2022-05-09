#include "Comment.h"
#include <cstring>

#pragma warning(disable : 4996)

Comment::Comment(const char* username, const char* content)
{
	strcpy(this->username, username);
	strcpy(this->content, content);
}

Comment::Comment()
{

}

bool Comment::setCommentator(const char* username)
{
	return true;
}
bool Comment::setContent(char* content)
{
	return true;
}

const char* Comment::getCommentator() const
{
	return username;
}

const  char* Comment::getContent() const
{
	return content;
}