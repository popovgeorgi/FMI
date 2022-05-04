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

			User& user = library.login(username, password);
			cout << "Welcome, " << user.getUsername() << "!" << endl;

			while (true)
			{
				cout << ">";
				cin >> command;
				if (command == "view")
				{

				}
				else if (command == "read")
				{

				}
				else if (command == "rate")
				{

				}
				else if (command == "comment")
				{

				}
				else if (command == "rates")
				{

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