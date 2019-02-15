#pragma once

#include <iostream>
#include <fstream>
#include <chrono>

#define NUMHANDS 1000
#define HANDSIZE 5
#define ROWSIZE 20
#define NUMVALUES 13

class P54
{
public:
	P54();

	void start();

private:

	void readFile(char*, int);
	
	void fillHand(char*, int*, int);
	void clearHands(int*, int*);
	int  handRank(char*, int*, int);
	
	bool royal(int*);
	bool straight(int*);
	bool fourOAK(int*);
	bool threeOAK(int*);
	bool twoPair(int*);
	bool onePair(int*);
	
	bool compareRank(int*, int*, int);
	bool findHighest(int*, int*);
	bool compareMatch(int*, int*, int);
	bool compareTwoPair(int*, int*);
	bool compareOnePair(int*, int*);
	
};
