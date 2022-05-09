#include <iostream>
#include "Kindle.h"

using namespace std;

int main()
{
	Kindle library;
	User* user = nullptr;

	while (true)
	{
		if (user == nullptr)
		{
			char command[100];
			cout << ">";
			cin >> command;
			if (strcmp(command, "signup") == 0)
			{
				char username[25];
				char password[30];
				cout << ">" << "Enter username: ";
				cin >> username;
				cout << ">" << "Enter password: ";
				cin >> password;

				bool result = library.registrate(username, password);
				if (!result)
				{
					cout << "Error!" << endl;;
				}
				else
				{
					cout << "User registered!" << endl;
				}

				continue;
			}
			else if (strcmp(command, "login") == 0)
			{
				char username[25];
				char password[30];
				cout << ">" << "Enter username: ";
				cin >> username;
				cout << ">" << "Enter password: ";
				cin >> password;

				user = library.login(username, password);
				if (user == nullptr)
				{
					cout << "Incorrect data!";
					continue;
				}
				cout << "Welcome, " << user->getUsername() << "!" << endl;
				continue;
			}
			else if (strcmp(command, "exit") == 0)
			{
				library.saveBooks();
				library.saveUsers();
				return 0;
			}
			else
			{
				cout << "Invalid command!";
				continue;
			}
		}
		else
		{
			char command[100];

			while (true)
			{
				cout << ">";
				cin >> command;
				if (strcmp(command, "view") == 0)
				{
					const MyVector<Book> allBooks = library.getAllBooks();
					int bookCount = allBooks.getSize();
					for (size_t i = 0; i < bookCount; i++)
					{
						cout << allBooks[i].getId() << ". " << allBooks[i].getTitle() << " by " << allBooks[i].getAuthor() << '\n';
					}
				}
				else if (strcmp(command, "read") == 0)
				{
					// only if you have not read it!

					char title[100];
					cin >> title;
					int id = library.findIdByName(title);
					if (id == -1)
					{
						cout << "There is no such book!" << '\n';
						continue;
					}
					user->read(id);
				}
				else if (strcmp(command, "rate") == 0)
				{
					// only people who have not read the book
					

					char title[100];
					cin >> title;
					int id = library.findIdByName(title);
					if (user->isAuthor(id) || !(user->hasRead(id)))
					{
						cout << "You cannot rate this!" << '\n';
						continue;
					}

					double rating;
					cin >> rating;
					library.rate(user->getUsername(), title, rating);
				}
				else if (strcmp(command, "comment") == 0)
				{
					char title[100];
					cin >> title;
					char comment[100];
					cin >> comment;

					library.comment(user->getUsername(), title, comment);
				}
				else if (strcmp(command, "comments") == 0)
				{
					//implement
					char title[100];
					cin >> title;
					const MyVector<Comment>* comments = library.getCommentsForBook(title);
					if (comments == nullptr)
					{
						cout << "Wrong title!" << '\n';
						continue;
					}

					int ratesCount = comments->getSize();
					for (size_t i = 0; i < ratesCount; i++)
					{
						cout << comments->operator[](i).getCommentator() << " commented " << comments->operator[](i).getContent() << '\n';
					}
				}
				else if (strcmp(command, "rates") == 0)
				{
					char title[100];
					cin >> title;
					const MyVector<Rate>* rates = library.getRatesForBook(title);
					if (rates == nullptr)
					{
						cout << "Wrong title!" << '\n';
						continue;
					}

					int ratesCount = rates->getSize();
					for (size_t i = 0; i < ratesCount; i++)
					{
						cout << rates->operator[](i).getRater() << " rated " << rates->operator[](i).getRating() << " stars" << '\n';
					}
				}
				else if (strcmp(command, "write") == 0)
				{
					Book book;
					char title[100];
					char pagesCount;

					cout << ">" << "Enter title: ";
					cin >> title;
					book.setTitle(title);
					book.setAuthor(user->getUsername());
					cout << ">" << "Enter pages count: ";
					cin >> pagesCount;
					for (size_t i = 0; i < pagesCount - 48; i++)
					{
						char content[500];
						// why cin.ignore()
						cin.ignore();
						cin.getline(content, 500);
						Page page(i + 1, content);
						book.addPage(page);
					}

					library.addBook(book);
					user->addToWroteCollection(library.findIdByName(title));
				}
				else if (strcmp(command, "addPage") == 0)
				{
					char title[100];
					cin >> title;
					int id = library.findIdByName(title);
					if (!user->isAuthor(id))
					{
						cout << "You have not written this book!" << '\n';
						continue;
					}

					char content[200];
					cin.getline(content, 200);
					Book& book = library.getBookByTitle(title);
					int pagesCount = book.getPagesCount();
					Page page(pagesCount + 1, content);

					book.addPage(page);
				}
				else if (strcmp(command, "logout") == 0)
				{
					user = nullptr;
					cout << "You've logged out!" << '\n';
					break;
				}
				else if (strcmp(command, "exit") == 0)
				{
					library.saveBooks();
					library.saveUsers();
					return 0;
				}
				else
				{
					cout << "Invalid command!" << endl;
				}
			}
		}
	}
}