#include "P9.h"

P9::P9()
{
	found = true;
	start();
}

void P9::start()
{
	std::cout << "Problem 9" << std::endl;

	//get a value s to find a pythegorean triplet which meets requirements
	//a + b + c = s and a^2 + b^2 = c^2 and a < b < c
	std::cout << "This program will find a pythagorean triplet within the number (x) if it exists." << std::endl
			  << "Requirements: 1) a + b + c = x" << std::endl
			  << "              2) a^2 + b^2 = c^2" << std::endl
			  << "              3) a < b < c" << std::endl
			  << "Enter a value for x: ";

	//get a value for x
	std::cin >> x;
	
	//get current time (start)
	auto start = std::chrono::high_resolution_clock::now();

	//set start values with a and b being minimum values  and c being the reminder out of 1000
	//set according to a < b < c
	a = 3;
	b = 4;
	c = x - b - a;
	
	//since a < b < c the maximum value a can be is the floor of (x - 3) / 3
	//(x-3) since the minimum value of a is 3
	//use ceil here since the loop is using < instead of <=
	while(a < ceil((x - 3) / 3))
	{
		//loop through every possible combination of b and c with current a value
		while (b < c)
		{
			//if pythagoren triplet is found jump out of loops
			if ((a*a) + (b*b) == (c*c))
			{
				found = true;
				goto end;
			}

			//increment b and decrement c
			b++;
			c--;
		}

		//increment a and set b according to a
		//let c be the reminder out of x after subtracting a and b
		a++;
		b = a + 1;
		c = x - b - a;
	}
	
	end:

	//get current time (finish)
	auto finish = std::chrono::high_resolution_clock::now();

	//print elapsed time in nanoseconds
	auto time = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count();
	std::cout << std::endl << "Elapsed time: " << time << " nanoseconds" << std::endl;
	
	//print success message with product of a * b * c or fail message
	if (found)
		std::cout << "The pythegorean triplet found within the sum of " << x << " is: " << std::endl
				  << a << "^2 * " << b << "^2 = " << c << "^2 with " << a << " + " << b << " + " << c << " = " << x << std::endl
				  << "The product of " << a << " * " << b << " * " << c << " is: " << a * b * c << std::endl;
	else
		std::cout << "No pythagorean triplet was found within " << x << "." << std::endl;

	std::cin.ignore();
}