//Project Euler
//
//PROBLEM 20
//Solution by Joseph Goodknight
//j@JosephGoodknight.com

// n! means n × (n − 1) × ... × 3 × 2 × 1
//
// For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
// and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27.
//
// Find the sum of the digits in the number 100!

#include <iostream>
#include <time.h>

int main()
{
	clock_t startTime = clock();

	//according to wolfram alpha, 100! = ...
	std::string hundred_factorial = "93326215443944152681699238856266700490715968264381621468592963895217599993229915608941463976156518286253697920827223758251185210916864000000000000000000000000";

	int zero_ascii_value = 48;

	int digit_sum = 0;
	for(char a : hundred_factorial) {
		digit_sum = digit_sum + (int)a - zero_ascii_value;
	}

	clock_t endTime = clock();
	std::cout << "\n" << "ANSWER: " <<  digit_sum;
	int clocks_per_ms = CLOCKS_PER_SEC / 1000;
	std::cout << "\n" << "CACLULATED IN: " <<  ((double)endTime - (double)startTime) / (double)clocks_per_ms <<" ms\n";
	return 0;
}
