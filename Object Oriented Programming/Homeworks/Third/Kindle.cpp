#include <fstream>
#include "Page.h"
#include "Kindle.h"

using namespace std;

Kindle::Kindle()
{
	loadUsers();
	loadBooks();
	//load books
	ifstream inFile("Users.txt");
	if (!inFile)
	{
		// what to do here
	}

	char input[50];

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
}

User& Kindle::login(const char* username, const char* password)
{
}

const Book* Kindle::getAllBooks() const
{

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
	while (true)
	{
		inFile.getline(input, 50);
		if (inFile.eof())
		{
			break;
		}

		Book book;
		book.setTitle(input);
		inFile.getline(input, 50);
		book.setAuthor(input);
		inFile.getline(input, 50);
		book.setRating(atoi(input));

		char content[500];
		int index = 1;
		while (true)
		{
			inFile.getline(content, 500);
			if (strlen(content) == 0)
			{
				break;
			}

			Page page;
			page.setId(index);
			page.setContent(content);

			book.addPage(page);
			index++;
		}

		// get comments;
	}
}