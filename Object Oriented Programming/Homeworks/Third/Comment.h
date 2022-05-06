#pragma once
class Comment
{
	char username[50];
	char content[200];

public:
	Comment();

	bool setCommentator(const char* username);
	bool setContent(char* content);
};