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
//NOT 76 nor 172 nor 174 nor 173

#include <iostream>
#include <time.h>

int main()
{
	clock_t startTime = clock();

	int currentYear = 1900;
	bool leapYear = false;
	int currentMonth = 1;
	int currentDate = 1;
	int currentDay = 1;

	int JANUARY = 1;
	int FEBRUARY = 2;
	int MARCH = 3;
	int APRIL = 4;
	int MAY = 5;
	int JUNE = 6;
	int JULY = 7;
	int AUGUST = 8;
	int SEPTEMBER = 9;
	int OCTOBER = 10;
	int NOVEMBER = 11;
	int DECEMBER = 12;


	int numberOfFirstSundays = 0;

	bool monthFlip = false;
	bool yearFlip = false;

	while( currentYear < 2001) {
		// std::cout << ".";
		if(currentDay == 7 && currentDate == 1 && currentYear > 1900) {
			numberOfFirstSundays = numberOfFirstSundays + 1;
			std::cout << currentDay << ", " << currentDate << "-" << currentMonth << "-" << currentYear << "\n";
		}

		//Day is simple
		currentDay = currentDay + 1;
		if(currentDay == 8) {
			currentDay = 1;
		}

		//Date/Month/year are all coupled
		currentDate = currentDate + 1;
		if(!leapYear && currentMonth == FEBRUARY  && currentDate == 28 + 1 ) {
			monthFlip = true;
		} else if(leapYear && currentMonth == FEBRUARY  && currentDate == 29 + 1 ) {
			monthFlip = true;
		} else if( currentDate == 30 + 1 && (currentMonth == SEPTEMBER || currentMonth == APRIL ||  currentMonth == JUNE ||  currentMonth == NOVEMBER) ) {
			monthFlip = true;
		} else if( currentDate == 31 + 1) {
			monthFlip = true;
		} else {
			monthFlip = false;
		}
		if(monthFlip) {
			currentMonth = currentMonth + 1;
			currentDate = 1;
			monthFlip = false;
			if(currentMonth == 13) {
				currentYear = currentYear + 1;
				currentMonth = 1;
				//leap year?
				if(currentYear % 4 == 0 && currentYear % 100 != 0) {
					leapYear = true;
				} else if(currentYear % 400 == 0) {
					leapYear = true;
				} else {
					leapYear = false;
				}
			}
		}

	}


	clock_t endTime = clock();
	std::cout << "\n" << "ANSWER: " <<  numberOfFirstSundays;
	int clocks_per_ms = CLOCKS_PER_SEC / 1000;
	std::cout << "\n" << "CACLULATED IN: " <<  ((double)endTime - (double)startTime) / (double)clocks_per_ms <<" ms\n";
	return 0;
}
