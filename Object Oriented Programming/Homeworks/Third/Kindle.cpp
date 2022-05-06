#include <fstream>
#include "Page.h"
#include "Kindle.h"
#include "Rate.h"

using namespace std;

Kindle::Kindle()
{
	loadUsers();
	loadBooks();
}

bool Kindle::registrate(const char* username, const char* password)
{
	// check if user already exists

	ofstream outFile("Users.txt", ios::app);

	outFile << username << '\n';
	outFile << password << '\n';
	outFile << '\n';
	outFile << '\n';
	outFile << '\n';

	outFile.close();

	return true;
}

const myVector<Rate>& Kindle::getRatesForBook(const char* title) const
{
	int size = library.getSize();
	for (size_t i = 0; i < size; i++)
	{
		if (library[i].getTitle() == title)
		{
			return library[i].getRatings();
		}
	}
}

void Kindle::rate(const char* username, const char* title, double rating)
{
	int size = library.getSize();
	for (size_t i = 0; i < size; i++)
	{
		if (library[i].getTitle() == title)
		{
			library[i].setRating(username, rating);
		}
	}
}

User* Kindle::login(const char* username, const char* password)
{
	int usersCount = users.getSize();
	for (size_t i = 0; i < usersCount; i++)
	{
		if (strcmp(username, users[i].getUsername()) == 0 && strcmp(password, users[i].getPassword()) == 0)
		{
			auto temp = users[i];
			return &temp;
		}
	}

	return nullptr;
}

int Kindle::findIdByName(const char* name) const
{
	int size = titleToId.getSize();
	for (size_t i = 0; i < size; i++)
	{
		if (strcmp(titleToId[i].key, name) == 0)
		{
			return titleToId[i].value;
		}
	}

	return -1;
}

bool Kindle::userExists(const char* username, const char* password)
{
	int usersCount = users.getSize();
	for (size_t i = 0; i < usersCount; i++)
	{
		if (strcmp(username, users[i].getUsername()) == 0 && strcmp(password, users[i].getPassword()) == 0)
		{
			return true;
		}
	}

	return false;
}

const myVector<Book>& Kindle::getAllBooks() const
{
	return library;
}

void Kindle::loadUsers()
{
	ifstream inFile("Users.txt");
	if (!inFile)
	{
		// what to do here
	}

	char input[50];
	while (true)
	{
		inFile.getline(input, 50);
		if (inFile.eof())
		{
			break;
		}

		User user;
		user.setUsername(input);
		inFile.getline(input, 50);
		user.setPassword(input);

		inFile.getline(input, 50);
		if (strlen(input) != 0)
		{
			for (size_t i = 0; i < strlen(input); i++)
			{
				if (i % 2 == 0)
				{
					user.addToReadCollection(i);
				}
			}
		}

		inFile.getline(input, 50);
		if (strlen(input) != 0)
		{
			for (size_t i = 0; i < strlen(input); i++)
			{
				if (i % 2 == 0)
				{
					user.addToWroteCollection(i);
				}
			}
		}

		users.insert(user);
	}
}

void Kindle::loadBooks()
{
	ifstream inFile("Books.txt");
	if (!inFile)
	{
		// what to do here
	}

	char input[50];
	int bookIndex = 1;
	while (true)
	{
		inFile.getline(input, 50);
		if (inFile.eof())
		{
			break;
		}

		Book book;
		book.setTitle(input);
		KeyValuePair<int, const char*> idTitle(bookIndex, input);
		KeyValuePair<const char*, int> titleId(input, bookIndex);
		idToTitle.insert(idTitle);
		titleToId.insert(titleId);
		inFile.getline(input, 50);
		book.setAuthor(input);
		inFile.getline(input, 50);

		char content[500];
		int pageIndex = 1;
		while (true)
		{
			inFile.getline(content, 500);
			if (strlen(content) == 0)
			{
				break;
			}

			Page page;
			page.setId(pageIndex);
			page.setContent(content);

			book.addPage(page);
			pageIndex++;
		}
		char input[200];
		while (true)
		{
			inFile.getline(input, 50);
			if (strlen(content) == 0)
			{
				break;
			}

			Comment comment;
			comment.setCommentator(input);
			inFile.getline(input, 200);
			comment.setContent(input);
		}
		while (true)
		{
			inFile.getline(input, 100);
			if (strlen(content) == 0)
			{
				break;
			}

			Rate rate;
			rate.setRater(input);
			inFile.getline(input, 20);
			rate.setRating(atoi(input));
		}

		bookIndex++;
	}
}