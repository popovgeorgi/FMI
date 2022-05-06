#include <iostream>
#include "Kindle.h"

using namespace std;

int main()
{
	Kindle library;

	while (true)
	{
		char command[100];
		cout << ">";
		cin.getline(command, 100);
		if (command == "signup")
		{
			char username[25];
			char password[30];
			cout << ">" << "Enter username: ";
			cin.getline(username, 25);
			cout << ">" << "Enter password: ";
			cin.getline(password, 30);

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
		else if (command == "login")
		{
			char username[25];
			char password[30];
			cout << ">" << "Enter username: ";
			cin.getline(username, 25);
			cout << ">" << "Enter password: ";
			cin.getline(password, 30);

			User* user = library.login(username, password);
			if (user == nullptr)
			{
				cout << "Incorrect data!";
				continue;
			}
			cout << "Welcome, " << user->getUsername() << "!" << endl;

			while (true)
			{
				cout << ">";
				cin >> command;
				if (command == "view")
				{
					const myVector<Book> allBooks = library.getAllBooks();
					int bookCount = allBooks.getSize();
					for (size_t i = 0; i < bookCount; i++)
					{
						cout << allBooks[i].getId() << ". " << allBooks[i].getTitle() << " by " << allBooks[i].getAuthor() << '\n';
					}
				}
				else if (command == "read")
				{
					char title[100];
					cin.getline(title, 100);
					int id = library.findIdByName(title);
					user->read(id);
				}
				else if (command == "rate")
				{
					char title[100];
					double rating;
					cin >> title;
					cin >> rating;
					library.rate(user->getUsername(), title, rating);
				}
				else if (command == "comment")
				{

				}
				else if (command == "rates")
				{
					char title[100];
					cin.getline(title, 100);
					myVector<Rate> rates = library.getRatesForBook(title);
				}
				else if (command == "write")
				{

				}
				else if (command == "addPage")
				{

				}
				else if (command == "logout")
				{

				}
				else
				{
					cout << "Invalid command!" << endl;
				}
			}
		}
		else
		{
			cout << "Invalid command!";
			continue;
		}
	}
}