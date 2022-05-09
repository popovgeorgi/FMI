#include "Page.h"
#include <cstring>

#pragma warning(disable : 4996)

Page::Page() {}

Page::Page(int id, const char* content)
{
	setId(id);
	setContent(content);
}

void Page::setId(int id)
{
	this->id = id;
}
void Page::setContent(const char* content)
{
	strcpy(this->content, content);
}

const char* Page::getContent() const 
{
	return content;
}