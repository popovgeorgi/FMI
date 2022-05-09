#include "Rate.h"
#include <cstring>

#pragma warning(disable : 4996)

Rate::Rate() {}

Rate::Rate(const char* username, double rating)
{
	//validate
	strcpy(this->username, username);
	this->rating = rating;
}

bool Rate::setRater(const char* username)
{
	//validate
	strcpy(this->username, username);

	return true;
}
bool Rate::setRating(double rating)
{
	//validate
	this->rating = rating;

	return true;
}

const char* Rate::getRater() const
{
	return username;
}

double Rate::getRating() const
{
	return rating;
}