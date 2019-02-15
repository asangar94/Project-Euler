#include "P54.h"

P54::P54() { start(); }

void P54::start()
{
	//declare variables
	//h1/h2 = hand 1 rank/hand 2 rank
	//arrLen = number of characters needed
	//h1values/h2values = arrays used to store the number of each type of card in each hand
	//cards = the array of characters
	int h1, h2, wins = 0, arrLen = NUMHANDS * ROWSIZE;
	int h1values[13], h2values[13];
	char *cards = new char[arrLen];

	//set the arrays to 0 (initialize)
	clearHands(h1values, h2values);
	//read in the hands into the character array
	readFile(cards, arrLen);

	//get current time
	auto start = std::chrono::high_resolution_clock::now();

	//loop for each pair of hands (check if hand 1 is the winner for each pair of hands)
	for (int i = 0; i < arrLen; i += ROWSIZE)
	{
		//fill in the arrays with the values for each hand
		fillHand(cards, h1values, i);
		fillHand(cards, h2values, i+10);

		//get the ranks of both hands
		h1 = handRank(cards, h1values, i);
		h2 = handRank(cards, h2values, i+10);

		//if hand 1 has a higher rank, increment wins
		if (h1 > h2) wins++;
		//if there is a tie in rank, find the winner
		else if (h1 == h2)
			//if hand 1 wins, increment wins
			if (compareRank(h1values, h2values, h1)) wins++;
		
		//reset the hand values for the next pair
		clearHands(h1values, h2values);
	}

	//get current time
	auto finish = std::chrono::high_resolution_clock::now();

	//print elapsed time in nanoseconds
	auto time = std::chrono::duration_cast<std::chrono::nanoseconds>(finish - start).count();
	std::cout << "Elapsed time: " << time << " nanoseconds" << std::endl;

	//print the number of wins for hand 1
	std::cout << wins << std::endl;

	//delete dynamic memory
	delete[] cards;
}

//read in the hands from the file into a character array
void P54::readFile(char *cards, int n)
{
	int temp = n;
	std::ifstream file("P54_Poker.txt");
	if (!file.is_open()) perror("File not found.");

	while (temp > 0) file >> cards[n-(temp--)];

	file.close();
}

//fill in the array for the hand values
void P54::fillHand(char *cards, int *values, int index)
{
	for (int i = 0; i < HANDSIZE; i++)
	{
		switch (cards[index + (i * 2)])
		{
		case '2': values[0]++; break;
		case '3': values[1]++; break;
		case '4': values[2]++; break;
		case '5': values[3]++; break;
		case '6': values[4]++; break;
		case '7': values[5]++; break;
		case '8': values[6]++; break;
		case '9': values[7]++; break;
		case 'T': values[8]++; break;
		case 'J': values[9]++; break;
		case 'Q': values[10]++; break;
		case 'K': values[11]++; break;
		case 'A': values[12]++; break;
		default: break;
		}
	}
}

void P54::clearHands(int *h1values, int *h2values)
{
	//set all values in both arrays to 0
	for (int i = 0; i < NUMVALUES; i++)
		h1values[i] = h2values[i] = 0;
}

int P54::handRank(char *cards, int *values, int index)
{
	bool Flush = false, Straight = false;

	//check if all the suits are the same (flush)

	if (cards[index + 1] == cards[index + 3] &&
		cards[index + 1] == cards[index + 5] && 
		cards[index + 1] == cards[index + 7] && 
		cards[index + 1] == cards[index + 9]) Flush = true;

	//*** [RANK 10] Royal Flush: 10 J Q K A (same suit) ***

	if (royal(values) && Flush) return 10;

	//*** [RANK 9] Straight Flush: Five consecutive values (same suit) ***

	Straight = straight(values);

	if (Straight && Flush) return 9;
	
	//*** [RANK 8] Four of a Kind: Four cards (same value) ***

	if (fourOAK(values)) return 8;

	//*** [RANK 7] Full House: Three of a kind and a pair ***

	if (threeOAK(values) && onePair(values)) return 7;

	//*** [RANK 6] Flush: Five cards (same suit) ***

	if (Flush) return 6;
	 
	//*** [RANK 5] Straight: Five consecutive values ***

	if (Straight) return 5;

	//*** [RANK 4] Three of a Kind: Three cards (same value) ***

	if (threeOAK(values)) return 4;

	//*** [RANK 3] Two Pairs: Two pairs (different value) ***

	if (twoPair(values)) return 3;

	//*** [RANK 2] One Pair: Two Cards (same Value) ***

	if (onePair(values)) return 2;

	//*** [RANK 1] Highest Card ***

	return 1;
}

//check if the values are 10 J Q K A
bool P54::royal(int *values)
{
	if (values[8] && values[9] && values[10] && values[11] && values[12]) return true;
	else return false;
}

//check if all 5 values are consecutive
bool P54::straight(int *values)
{
	for (int i = 0; i < NUMVALUES - 5; i++)
		if (values[i] && values[i+1] && values[i+2] && values[i+3] && values[i+4]) return true;

	return false;
}

//check the array for a 4 count on one value
bool P54::fourOAK(int *values)
{
	for (int i = 0; i < NUMVALUES; i++)
		if (values[i] == 4) return true;

	return false;
}

//check the array for a 3 count on one value
bool P54::threeOAK(int *values)
{
	for (int i = 0; i < NUMVALUES; i++)
		if (values[i] == 3) return true;

	return false;
}

//check the array for a 2 counts on 2 different values
bool P54::twoPair(int *values)
{
	int firstPair = -1;

	for (int i = 0; i < NUMVALUES; i++)
	{
		if (firstPair == -1 && values[i] == 2) firstPair = i;
		else if (values[i] == 2) return true;
	}

	return false;
}

//check the array for a 2 count on one value
bool P54::onePair(int *values)
{
	for (int i = 0; i < NUMVALUES; i++)
		if (values[i] == 2) return true;

	return false;
}

//find the winner if tied in rank
//return true = hand 1, return false = hand 2/split
bool P54::compareRank(int *h1values, int *h2values, int rank)
{
	switch (rank)
	{
	//Straight Flush, Flush, Straight, Highest Card
	case 9: case 6: case 5: case 1:
		return findHighest(h1values, h2values);
		break;
	//Four of a Kind
	case 8:
		return compareMatch(h1values, h2values, 4);
		break;
	//Full House, Three of a Kind
	case 7: case 4:
		return compareMatch(h1values, h2values, 3);
		break;
	//Two Pair
	case 3:
		return compareTwoPair(h1values, h2values);
		break;
	//One Pair
	case 2:
		return compareOnePair(h1values, h2values);
		break;
	//Royal Flush (split)
	default: return false; break;
	}
}

//used for Straight Flush, Flush, Straight, Highest Card comparison
bool P54::findHighest(int *h1values, int *h2values)
{
	for (int i = NUMVALUES - 1; i > 0; i--)
	{	
		//return true if the highest card is in hand 1
		if (h1values[i] > h2values[i]) return true;
		//return false if the highest card is in hand 2
		else if (h2values[i] > h1values[i]) return false;
	}

	//return false if the hands are equal (split)
	return false;
}

//used for 4 of a Kind and 3 of a Kind comparison
bool P54::compareMatch(int *h1values, int *h2values, int type)
{
	for (int i = NUMVALUES - 1; i > 0; i--)
	{
		//returns true if the value in hand 1 is equal to that of type
		// (i.e. hand 1 has the higher 4/3 of a kind)
		if (h1values[i] == type) return true;
		//returns false if the value in hand 2 is equal to that of type
		// (i.e. hand 2 has the higher 4/3 of a kind)
		else if (h2values[i] == type) return false;
	}

	//should never reach this case
	return false;
}

//used for Two Pair comparison
bool P54::compareTwoPair(int *h1values, int *h2values)
{
	//used to store the indexs of the pairs
	//h1p1 = hand 1 pair 1   h1p2 = hand 1 pair 2
	//h2p1 = hand 2 pair 1   h2p2 = hand 2 pair 2
	int h1p1 = -1, h1p2 = -1, h2p1 = -1, h2p2 = -1;

	//search through the arrays to find the pair indexes
	for (int i = NUMVALUES - 1; i > 0; i--)
	{
		if (h1values[i] == 2 && h1p1 == -1) h1p1 = i;
		else if (h1values[i] == 2) h1p2 = i;

		if (h2values[i] == 2 && h2p1 == -1) h2p1 = i;
		else if (h2values[i] == 2) h2p2 = i;
	}

	//if hand 1 has a higher first pair return true
	if (h1p1 > h2p1) return true;
	//if hand 2 has a higher first pair return false
	else if (h2p1 > h1p1) return false;
	//else they are equal
	//if hand 1 has a higher second pair return true
	else if (h1p2 > h2p2) return true;
	//if hand 2 has a higher second pair return false
	else if (h2p2 > h1p2) return false;
	//else both first and second pairs are equal
	else
	{
		//search for the higher single card (kicker)
		for (int i = NUMVALUES - 1; i > 0; i--)
		{
			//return true if hand 1 is higher
			if (h1values[i] == 1 && h2values[i] != 1) return true;
			//return false if hand 2 is higher
			else if (h2values[i] == 1 && h1values[i] != 1) return false;
		}
	}

	//return false if they are equal (split)
	return false;
}

//used for One Pair comparison
bool P54::compareOnePair(int *h1values, int *h2values)
{
	//used to store the indexes of the pairs
	//h1p = hand 1 pair   h2p = hand 2 pair
	int h1p = -1, h2p = -1;

	//search through the array to find the pair indexes
	for (int i = NUMVALUES - 1; i > 0; i--)
	{
		if (h1values[i] == 2) h1p = i;
		if (h2values[i] == 2) h2p = i;
	}

	//if hand 1 has a higher pair return true
	if (h1p > h2p) return true;
	//if hand 2 has a higher pair return false
	else if (h2p > h1p) return false;
	//else they are equal
	else
	{
		//find which hand has the highest value that isnt a pair
		//(search through the kickers while ignoring the pair)
		for (int i = NUMVALUES - 1; i > 0; i--)
		{
			//if a hand 1 has a kicker and hand 2 has either a pair or nothing
			//return true (hand 1 wins)
			if (h1values[i] == 1 && h2values[i] != 1) return true;
			//if a hand 2 has a kicker and hand 1 has either a pair or nothing
			//return false (hand 2 wins)
			else if (h2values[i] == 1 && h1values[i] != 1) return false;
		}
	}

	//return false if they are equal (split)
	return false;
}

