#pragma once

class Page
{
	int id;
	char* content;

public:
	void setId(int id);
	void setContent(const char* content);
};