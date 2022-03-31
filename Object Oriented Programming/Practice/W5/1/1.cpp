#include <iostream>

class Interval
{
	int a;
	int b;

	void setInterval(int a, int b)
	{
		if (a > b)
		{
			a = 0;
			b = 0;
		}
		else
		{
			this->a = a;
			this->b = b;
		}
	}


public:
	Interval()
	{
		a = 0;
		b = 0;
	}

	Interval(int a, int b)
	{
		setInterval(a, b);
	}


	int getA() const
	{
		return a;
	}

	int getB() const
	{
		return b;
	}

	int getLength() const
	{
		return b - a;
	}

	bool isInInterval(int n) const
	{
		if (n >= a && n <= b)
		{
			return true;
		}

		return false;
	}
};

int main()
{
	Interval interval(1,3);
}
