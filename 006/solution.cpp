//Project Euler
//
//PROBLEM 6
//Solution by Joseph Goodknight
//j@JosephGoodknight.com

// The sum of the squares of the first ten natural numbers is,

// 1^2 + 2^2 + ... + 10^2 = 385
// The square of the sum of the first ten natural numbers is,

// (1 + 2 + ... + 10)^2 = 55^2 = 3025
// Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 − 385 = 2640.

// Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.

#include <iostream>
#include <vector>
#include <list>
#include <cmath>

int maxNaturalNumber = 100;

int sumOfAllNumbersLessThan(int N)
{
	int output = 0;
	for (int i = 1; i < N; ++i)
	{
		output = output + i;
	}
	return output;
}

int sumOfAllSquaresLessThan(int N)
{
	int output = 0;
	for (int i = 1; i < N; ++i)
	{
		output = output + (int)std::pow(i, 2);
	}
	return output;
}
int main() 
{
	int sumSquares = sumOfAllSquaresLessThan(maxNaturalNumber + 1);
	int sum = sumOfAllNumbersLessThan(maxNaturalNumber + 1);
	std::cout << "\nANSWER: " << (int)std::pow(sum, 2) - sumSquares <<"\n";
	return 1;
}



