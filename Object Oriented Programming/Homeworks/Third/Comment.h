#pragma once
class Comment
{
	char username[50];
	char content[200];

public:
	Comment(const char* username, const char* content);
	Comment();

	bool setCommentator(const char* username);
	bool setContent(char* content);

	const char* getCommentator() const;
	const  char* getContent() const;
};