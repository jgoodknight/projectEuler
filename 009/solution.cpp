//Project Euler
//
//PROBLEM 9
//Solution by Joseph Goodknight
//j@JosephGoodknight.com
// A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,

// a^2 + b^2 = c^2
// For example, 3^2 + 4^2 = 9 + 16 = 25 = 52.

// There exists exactly one Pythagorean triplet for which a + b + c = 1000.
// Find the product abc


#include <iostream>
#include <vector>
#include <list>
#include <cmath>

#include <omp.h>

int maxNumber = 1000;

int sumOfThreeNumbers = maxNumber;

bool breakOut = false;

int main() 
{
	int a, b, c;
	double possibleC, decimalOfC;

	for (a = 1; a <= maxNumber; ++a)
	{
		for (b = a + 1; b < maxNumber; ++b)
		{
			// #pragma omp parallel for
			//did not speed up, because it necessitated dropping the break statement
			for (c = b; c < maxNumber; ++c)
			{
				//if this third loop seems stupid... it is but I got tired of diving into floating point crud and this seemed easier.
				//fun fact on my 
				if (std::pow(a, 2) + std::pow(b, 2)  == std::pow(c, 2) )
				{
					if (a + b + c == sumOfThreeNumbers)
					{
						std::cout << "\nANSWER: \n";
						std::cout << a << "^2 + " << b << "^2 = " << c << "^2 \n";
						std::cout << a << " + " << b << " + " << c << " = " << sumOfThreeNumbers << "\n";
						std::cout << a << " * " << b << " * " << c << " = " << a * b * c << "\n";
						breakOut = true;
						break;
					}
				}
			}
			if (breakOut) break;
		}
		if (breakOut) break;
	}
	return 0;
}



