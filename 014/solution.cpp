//Project Euler
//
//PROBLEM 14
//Solution by Joseph Goodknight
//j@JosephGoodknight.com

// Work out the first ten digits of the sum of the following one-hundred 50-digit numbers.

// e following iterative sequence is defined for the set of positive integers:

// n → n/2 (n is even)
// n → 3n + 1 (n is odd)

// Using the rule above and starting with 13, we generate the following sequence:

// 13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
// It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

// Which starting number, under one million, produces the longest chain?

// NOTE: Once the chain starts the terms are allowed to go above one million.

#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include <cmath>
#include <algorithm>


unsigned long long int nextNumberInSequence(unsigned long long input) {
	if(input % 2 == 0) {
		return input / 2;
	} else {
		return 3 * input + 1;
	}
}

unsigned long long  maxNumberToStartWith = 1000000;

int largestChainLength = 0;
unsigned long long int largestChainStarter = 0;

int main() 
{
	int chainLength;
	unsigned long long int currentNumberInSequence;
	for(unsigned long long int startingNumber = 1; startingNumber <= maxNumberToStartWith; startingNumber = startingNumber + 1) {
	// for(unsigned long long int startingNumber = maxNumberToStartWith; startingNumber > 1 ; startingNumber = startingNumber -1) {
		chainLength = 0;
		currentNumberInSequence = startingNumber;
		while(currentNumberInSequence != 1) {
			chainLength = chainLength + 1;
			currentNumberInSequence = nextNumberInSequence(currentNumberInSequence);
		}
		std::cout << "Chain starting at " << startingNumber << " has chain length of " << chainLength << "\n";
		if(chainLength > largestChainLength) {
			largestChainLength = chainLength;
			largestChainStarter = startingNumber;
		}

	}
	std::cout << "ANSWER: " << largestChainStarter << " has chain length of " << largestChainLength <<"\n";

	return 0;
}






