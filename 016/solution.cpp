//Project Euler
//
//PROBLEM 16
//Solution by Joseph Goodknight
//j@JosephGoodknight.com

// 2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.

// What is the sum of the digits of the number 2^1000?

#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include <cmath>
#include <algorithm>

#include <gmpxx.h>

typedef unsigned long long int integer;

integer expoenentArgument = 1000;
integer number = 1;

integer power(integer base, integer exponent) {
	integer output = 1;
	for(int i = 0; i < exponent; i++) {
		output = output * base;
	}
	return output;
}

mpz_class bigPower(mpz_class base, integer exponent) {
	mpz_class output("1");
	for(int i = 0; i < exponent; i++) {
		output = output * base;
	}
	return output;
}


int main() 
{
	mpz_class two("2");
	mpz_class toSumDigitsOf = bigPower(two, expoenentArgument);

	std::string theNumber = toSumDigitsOf.get_str(10);
	auto theNumberInChar = theNumber.c_str();
	integer digitSum = 0;

	for(int i = 0; i < theNumber.size(); ++i) {
		char currentDigitChar = (theNumber.c_str())[i];
		int digit = currentDigitChar - '0';
		digitSum = digitSum + digit;
	}

	std::cout << "\n" << "ANSWER: " <<  digitSum <<"\n";

	return 0;
}






