#include "P16.h"

P16::P16()
{
	num = pow(2, 1000);
	sum = 0; start();
}

void P16::start()
{
	printf("Problem 16\n");

	size = sprintf_s(str, "%lf", num);

	for (int i = 0; i < size-7; i++)
		sum += str[i] - '0';

	printf("%d", sum);
}