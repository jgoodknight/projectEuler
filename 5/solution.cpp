//Project Euler
//
//PROBLEM 5
//Solution by Joseph Goodknight
//j@JosephGoodknight.com

// 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

// What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?

#include <iostream>
#include <vector>
#include <list>
#include <cmath>

int maximumFactorValue = 20;

bool qIsDivisibleByAllNumbersLessThanN(int q, int N)
{
	for (int i = 1; i <= N; ++i)
	{
		if(q % i != 0)
		{
			return false;
		}
	}
	return true;
}


void printIntegerList(std::list<int> toBePrinted)
{
	std::cout << "(";
	for(int item : toBePrinted)
	{
		std::cout << item << ", ";
	}
	std::cout << ")";
}

long factorial(long n) {
	if(n < 1) {
		return 1;
	} else {
		return n * factorial(n - 1);
	}
}


std::list<int> primesLessThanN(int N)
{
	std::list<int> primeNumbers;
	primeNumbers.push_back(2);

	bool iIsPrime = true;

	for (int i = 3; i < N; ++i)
	{
		iIsPrime = true;
		for(int prime : primeNumbers) 
		{
			if (i % prime == 0)
			{
				iIsPrime = false;
				break;
			}
		}
		if(iIsPrime) 
		{
			primeNumbers.push_back(i);
		}
	}
	return primeNumbers;
}

int productOfIntegerList(std::list<int> toBeMultiplied)
{
	int output = 1;
	for(int item : toBeMultiplied)
	{
		output = output * item;
	}
	return output;
}


int main() 
{
	std::list<int> primeNumbers = primesLessThanN(maximumFactorValue);
	int minimumValue = productOfIntegerList(primeNumbers);
	int answer = 0;
	for (int i = minimumValue; i < factorial(maximumFactorValue); i = i + 2)
	{
		if(qIsDivisibleByAllNumbersLessThanN(i, maximumFactorValue))
		{
			answer = i;
			break;
		}
	}
	std::cout << "\nANSWER: " << answer <<"\n";
	return 1;
}



