#include <iostream>
#include "WordCollection.h"

using namespace std;

int main()
{
    WordCollection dict;
	((dict *= "Ivan") *= "Petur") *= "Alex";
	std::cout << dict["Alex"] << " " << dict["abc"] << std::endl; // 1 0
}
