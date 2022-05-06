#pragma once
class Rate
{
	char username[50];
	double rating;

public:
	Rate();
	Rate(const char* username, double rating);

	bool setRater(const char* username);
	bool setRating(double rating);
};