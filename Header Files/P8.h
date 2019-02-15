#pragma once

#include <iostream>
#include <string>
#include <chrono>

class P8
{
public:

	P8();

	void start();

private:

	int current[13];
	int64_t largestProduct, product;
	std::string num;
};