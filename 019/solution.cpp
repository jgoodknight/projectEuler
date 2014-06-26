//Project Euler
//
//PROBLEM 19
//Solution by Joseph Goodknight
//j@JosephGoodknight.com
// You are given the following information, but you may prefer to do some research for yourself.
//
// 1 Jan 1900 was a Monday.
// Thirty days has September,
// April, June and November.
// All the rest have thirty-one,
// Saving February alone,
// Which has twenty-eight, rain or shine.
// And on leap years, twenty-nine.
// A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.
// How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <time.h>

int main()
{
	clock_t startTime = clock();


	clock_t endTime = clock();
	std::cout << "\n" << "ANSWER: " <<  0;
	int clocks_per_ms = CLOCKS_PER_SEC / 1000;
	std::cout << "\n" << "CACLULATED IN: " <<  ((double)endTime - (double)startTime) / (double)clocks_per_ms <<" ms\n";
	return 0;
}
