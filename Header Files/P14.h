#pragma once

#include <iostream>
#include <chrono>

#define MAX 1000000

class P14
{
public:

	P14();

	void start();

private:

	int64_t chain(int64_t*, int64_t);
};