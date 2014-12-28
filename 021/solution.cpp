//Project Euler
//
//PROBLEM 21
//Solution by Joseph Goodknight
//j@JosephGoodknight.com

// Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
// If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of a and b are called amicable numbers.
//
// For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284.
// The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.
//
// Evaluate the sum of all the amicable numbers under 10000.

#include <iostream>
#include <vector>
#include <time.h>

int MAX_NUMBER = 10000;

std::vector<int> listOfProperDivisors(int targetNumber) {
	std::vector<int> output;
	for(int i = 1; i < targetNumber; i = i + 1) {
		if(targetNumber % i == 0) {
			output.push_back(i);
		}
	}
	return output;
}

int sumOfVector(std::vector<int> inputVector) {
	int output = 0;
	for(int a : inputVector) {
		output = output + a;
	}
	return output;
}

int sumOfProperDivisors(int inputInteger) {
	std::vector<int> vectorOfProperDivisors = listOfProperDivisors(inputInteger);
	return sumOfVector(vectorOfProperDivisors);
}

bool isAmicable(int possiblyAmicable) {
	int firstSum = sumOfProperDivisors(possiblyAmicable);
	int secondSum = sumOfProperDivisors(firstSum);
	return secondSum == possiblyAmicable && possiblyAmicable != firstSum;
}
int main()
{
	clock_t startTime = clock();

	int sum = 0;

	for(int i = 1; i < MAX_NUMBER; i = i + 1) {
		if(isAmicable(i)) {
			sum = sum + i;
			std::cout << i << "\n";
		}
	}

	clock_t endTime = clock();
	std::cout << "\n" << "ANSWER: " <<  sum;
	int clocks_per_ms = CLOCKS_PER_SEC / 1000;
	std::cout << "\n" << "CACLULATED IN: " <<  ((double)endTime - (double)startTime) / (double)clocks_per_ms <<" ms\n";
	return 0;
}
