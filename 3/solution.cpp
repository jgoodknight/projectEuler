//Project Euler
//
//PROBLEM 3
//Solution by Joseph Goodknight
//j@JosephGoodknight.com

// The prime factors of 13195 are 5, 7, 13 and 29.

// What is the largest prime factor of the number 600851475143 ?

#include <iostream>
#include <vector>
#include <list>
#include <cmath>


const long toBeFactored =  600851475143;


int main() {
	std::list<long> primeNumbers;

	long maxNumberToCheck = (long) std::sqrt(toBeFactored);

	primeNumbers.push_back(2);

	std::list<long> primeFactors;

	long numberForFactoring = toBeFactored;

	std::cout << "Generating Prime Numbers...\n";

	bool iIsPrime = true;

	long mostRecentFactor = 0;
	for (int i = 3; i < maxNumberToCheck; ++i)
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
			std::cout << "new prime: " << i << "\n";
			primeNumbers.push_back(i);

			if(numberForFactoring % i == 0) {
				mostRecentFactor = i;
				primeFactors.push_back(i);
				std::cout << i << " is a factor of " << toBeFactored << "\n";
				numberForFactoring = numberForFactoring / i;
			}
		}
	}

	// std::cout << "Finding Largest Prime Factor for " << toBeFactored << "\n";
	// long biggestFactor = 2;
	// for (long prime : primeNumbers)
	// {
	// 	if(toBeFactored % prime == 0) {
	// 		// std::cout << toBeFactored<< " is divisible by " << prime << "\n";
	// 		biggestFactor = prime;
	// 		break;
	// 	}
	// }

	std::cout << "\nANSWER: " << mostRecentFactor <<"\n";
}

