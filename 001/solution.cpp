//Project Euler
//
//PROBLEM 1
//Solution by Joseph Goodknight
//j@JosephGoodknight.com

//If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

//Find the sum of all the multiples of 3 or 5 below 1000.

#include <iostream>

int main() {
	int LESS_THAN = 1000;

	int total = 0;

	for (int numberUnderConsideration = 1; numberUnderConsideration < LESS_THAN; ++numberUnderConsideration)
	{
		if(numberUnderConsideration % 3 == 0 || numberUnderConsideration % 5 == 0) {
			total = total + numberUnderConsideration;
		}
	}

	std::cout << "\nANSWER: " << total <<"\n";
}
