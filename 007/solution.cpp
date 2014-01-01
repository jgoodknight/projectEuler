//Project Euler
//
//PROBLEM 7
//Solution by Joseph Goodknight
//j@JosephGoodknight.com

// By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

// What is the 10 001st prime number?

#include <iostream>
#include <vector>
#include <list>
#include <cmath>

int maxPrimeIndex = 10001;


int main() 
{
	std::list<long> primeNumbers;
	primeNumbers.push_back(2);

	std::cout << "Generating Prime Numbers...\n";

	bool iIsPrime = true;

	for (int i = 3; primeNumbers.size() != maxPrimeIndex; ++i)
	{
		iIsPrime = true;
		for(long prime : primeNumbers) 
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

	std::cout << "\nANSWER: " << primeNumbers.back() <<"\n";
}



