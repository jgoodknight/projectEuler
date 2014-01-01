//Project Euler
//
//PROBLEM 4
//Solution by Joseph Goodknight
//j@JosephGoodknight.com

// A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

// Find the largest palindrome made from the product of two 3-digit numbers.

#include <iostream>
#include <vector>
#include <list>
#include <cmath>

const long maximumNumber =  999;
const long minimumNumber =  100;


std::vector<int> digitsOfInteger(int integerToSplit)
{
	int numberOfDigits = 1 + (int) std::log10(integerToSplit);
	std::vector<int> output(numberOfDigits);

	int newDigit;
	int remainderOfNumber = integerToSplit;
	for (int digitNumber = 0; digitNumber < numberOfDigits; ++digitNumber)
	{
		newDigit = remainderOfNumber % 10;
		output[digitNumber] = newDigit;
		remainderOfNumber = (remainderOfNumber - newDigit) / 10;
	}
	return output;
}

bool integerIsPalindrome(int possiblePalindrome)
{
	std::vector<int> integerVector = digitsOfInteger(possiblePalindrome);
	int numberOfDigits = integerVector.size();
	int mirrorDigitIndex;
	for (int digitIndex = 0; digitIndex <= numberOfDigits / 2; ++digitIndex)
	{
		mirrorDigitIndex = numberOfDigits - digitIndex - 1;

		if (integerVector[digitIndex] != integerVector[ mirrorDigitIndex ])
		{
			return false;
		}
	}
	return true;
}

void printIntegerVector(std::vector<int> toBePrinted)
{
	std::cout << "(";
	for(int item : toBePrinted)
	{
		std::cout << item << ", ";
	}
	std::cout << ")";
}

int main() {
	int largestPalindrome = 0;
	int numberToCheck = 0;

	std::vector<int> candidatePalindromes;

	for (int factor1 = maximumNumber; factor1 >= minimumNumber ; --factor1)
	{
		for (int factor2 = maximumNumber; factor2 >= factor1 ; --factor2) 
		{
			numberToCheck = factor1 * factor2;
			if(integerIsPalindrome(numberToCheck)) {
				candidatePalindromes.push_back(numberToCheck);
				if(numberToCheck > largestPalindrome) {
					largestPalindrome = numberToCheck;
				}
			}
		}
	}
	// printIntegerVector(digitsOfInteger(920029));
	// std::cout << "\nANSWER: " << integerIsPalindrome(920029) <<"\n";
	printIntegerVector(candidatePalindromes);
	std::cout << "\nANSWER: " << largestPalindrome <<"\n";
}




