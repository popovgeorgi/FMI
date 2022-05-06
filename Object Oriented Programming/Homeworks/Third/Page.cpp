#include "Page.h"
#include <cstring>

#pragma warning(disable : 4996)

void Page::setId(int id)
{
	this->id = id;
}
void Page::setContent(const char* content)
{
	strcpy(this->content, content);
}