//Project Euler
//
//PROBLEM 10
//Solution by Joseph Goodknight
//j@JosephGoodknight.com
// The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

// Find the sum of all the primes below two million.

#include <iostream>
#include <vector>
#include <list>
#include <cmath>

#include <omp.h>

int maxPrimeValue = 2000000;

std::list<long> primeNumbers;


long count;

int main() 
{

	primeNumbers.push_back(2);
	count = 2;
	std::cout << "Generating Prime Numbers...\n";

	bool iIsPrime = true;

	for (int i = 3; i <= maxPrimeValue; ++i)
	{
		iIsPrime = true;
		for(long prime : primeNumbers) 
		{
			if (i % prime == 0 )
			{
				iIsPrime = false;
				break;
			}
			if (prime > std::sqrt(i))
			{
				break;
			}
		}
		if(iIsPrime) 
		{
			primeNumbers.push_back(i);
			count = count + i;
		}
	}

	std::cout << "\nANSWER: " << count <<"\n";

	return 0;
}



