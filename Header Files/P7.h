#pragma once

#include <iostream>
#include <chrono>

class P7
{
public:

	P7();

	void start();

private:

	bool isPrime(int);

	int counter, current, n;
};