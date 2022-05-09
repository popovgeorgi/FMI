#include <fstream>
#include <iostream>
#include "Page.h"
#include "Kindle.h"
#include "Rate.h"
#include "KeyValuePair.hpp"

using namespace std;

Kindle::Kindle()
{
	loadUsers();
	loadBooks();
}

bool Kindle::registrate(const char* username, const char* password)
{
	// check if user already exists
	if (userExists(username, password))
	{
		return false;
	}

	User user(username, password);
	users.insert(user);

	return true;
}

const MyVector<Rate>* Kindle::getRatesForBook(const char* title) const
{
	int size = library.getSize();
	for (size_t i = 0; i < size; i++)
	{
		if (strcmp(library[i].getTitle(), title) == 0)
		{
			return &(library[i].getRatings());
		}
	}

	return nullptr;
}

const MyVector<Comment>* Kindle::getCommentsForBook(const char* title) const
{
	int size = library.getSize();
	for (size_t i = 0; i < size; i++)
	{
		if (strcmp(library[i].getTitle(), title) == 0)
		{
			return &(library[i].getComments());
		}
	}

	return nullptr;
}

void Kindle::rate(const char* username, const char* title, double rating)
{
	int size = library.getSize();
	for (size_t i = 0; i < size; i++)
	{
		if (strcmp(library[i].getTitle(), title) == 0)
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
			return &users[i];
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

const MyVector<Book>& Kindle::getAllBooks() const
{
	return library;
}

void Kindle::addBook(Book& book)
{
	int librarySize = library.getSize();
	book.setId(librarySize + 1);
	library.insert(book);
	titleToId.insert(KeyValuePair<int>(book.getTitle(), librarySize + 1));
}

void Kindle::loadUsers()
{
	//creating the file if it does not exist
	ofstream outFile("Users.txt", ios::app);
	outFile.close();
	ifstream inFile("Users.txt");
	if (!inFile.is_open())
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
		if (strcmp(input, "") == 0)
		{
			continue;
		}

		User user;
		user.setUsername(input);
		inFile.getline(input, 50);
		user.setPassword(input);

		inFile.getline(input, 50);
		if (strlen(input) != 0)
		{
			for (size_t i = 0; i < strlen(input) - 1; i++)
			{
				if (i % 2 == 0)
				{
					user.addToReadCollection(input[i]);
				}
			}
		}

		inFile.getline(input, 50);
		if (strlen(input) != 0)
		{
			for (size_t i = 0; i < strlen(input) - 1; i++)
			{
				if (i % 2 == 0)
				{
					user.addToWroteCollection(input[i]);
				}
			}
		}

		users.insert(user);
	}
}

void Kindle::loadBooks()
{
	ofstream outFile("Books.txt", ios::app);
	outFile.close();
	ifstream inFile("Books.txt");
	if (!inFile.is_open())
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
		book.setId(bookIndex);
		book.setTitle(input);
		KeyValuePair<int> titleId(input, bookIndex);
		titleToId.insert(titleId);
		inFile.getline(input, 50);
		book.setAuthor(input);
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
			inFile.getline(input, 200);
			if (strlen(content) == 0)
			{
				break;
			}

			Comment comment;
			comment.setCommentator(input);
			inFile >> input;
			comment.setContent(input);
		}
		while (true)
		{
			inFile.getline(input, 200);
			if (strlen(input) == 0)
			{
				break;
			}

			Rate rate;
			rate.setRater(input);
			inFile >> input;
			rate.setRating(atoi(input));
		}

		library.insert(book);
		bookIndex++;
	}
}

void Kindle::comment(const char* username, const char* title, const char* comment)
{
	int size = library.getSize();
	for (size_t i = 0; i < size; i++)
	{
		if (strcmp(library[i].getTitle(), title) == 0)
		{
			library[i].addComment(username, comment);
		}
	}
}

Book& Kindle::getBookByTitle(const char* title)
{
	int size = library.getSize();
	for (size_t i = 0; i < size; i++)
	{
		if (strcmp(library[i].getTitle(), title) == 0)
		{
			return library[i];
		}
	}
}

void Kindle::saveBooks() const
{
	ofstream outFile("Books.txt");
	if (!outFile.is_open())
	{
		// what to do here
	}

	int booksCount = library.getSize();
	for (size_t i = 0; i < booksCount; i++)
	{
		Book& currentBook = library[i];
		outFile << currentBook.getTitle() << '\n';
		outFile << currentBook.getAuthor() << '\n';
		int pagesCount = currentBook.getPagesCount();
		for (size_t i = 0; i < pagesCount; i++)
		{
			outFile << currentBook.getPages()[i].getContent() << '\n';
		}
		outFile << '\n';
		int commentsCount = currentBook.getCommentsCount();
		for (size_t i = 0; i < commentsCount; i++)
		{
			outFile << currentBook.getComments()[i].getCommentator() << '\n';
			outFile << currentBook.getComments()[i].getContent() << '\n';
		}
		outFile << '\n';
		int ratesCount = currentBook.getRatesCount();
		for (size_t i = 0; i < ratesCount; i++)
		{
			outFile << currentBook.getRatings()[i].getRater() << '\n';
			outFile << currentBook.getRatings()[i].getRating() << '\n';
		}
		outFile << '\n';
	}
}

void Kindle::saveUsers() const
{
	ofstream outFile("Users.txt");
	if (!outFile.is_open())
	{
		// what to do here
	}

	int usersCount = users.getSize();
	for (size_t i = 0; i < usersCount; i++)
	{
		const User& user = users[i];
		outFile << user.getUsername() << '\n';
		outFile << user.getPassword() << '\n';

		int readBooksCount = user.getReadBooksCount();
		MyVector<int> readBooks = user.getReadBooks();
		for (size_t i = 0; i < readBooksCount; i++)
		{
			outFile << readBooks[i] << " ";
		}
		outFile << '\n';

		int writtenBooksCount = user.getWrittenBooksCount();
		MyVector<int> writtenBooks = user.getWrittenBooks();
		for (size_t i = 0; i < writtenBooksCount; i++)
		{
			outFile << writtenBooks[i] << " ";
		}
		outFile << '\n';
	}
}