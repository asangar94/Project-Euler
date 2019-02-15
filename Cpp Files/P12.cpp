#include <iostream>

int numDivisors(int);

int main()
{

	int64_t num = 1, i = 2;
	bool found = false;

	while (!found)
	{
		if (numDivisors(num) >= 500) found = true;
		num += i++;
	}

	std::cout << num << std::endl;

	return 0;
}

int numDivisors(int num)
{
	int divisors = 0;

	for (int i = 1; i < num + 1; i++)
		if (num % i == 0) divisors++;

	return divisors;
}