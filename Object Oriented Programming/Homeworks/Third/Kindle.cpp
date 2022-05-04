#include "Kindle.h"
#include <fstream>

using namespace std;

Kindle::Kindle()
{
	// load users, books, pages form memory;
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