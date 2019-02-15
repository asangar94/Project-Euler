#pragma once

#include <iostream>
#include <fstream>

class P13
{
public:

	P13();

	void start();

private:

	void readFile(char[100][50]);

	char inputs[100][50];
	int64_t numbers[100], sum;
};