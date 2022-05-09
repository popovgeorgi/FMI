#pragma once

class Page
{
	int id;
	char content[500];

public:
	Page();
	Page(int id, const char* content);
	void setId(int id);
	void setContent(const char* content);

	const char* getContent() const;
};