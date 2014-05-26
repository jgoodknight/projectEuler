//Project Euler
//
//PROBLEM 17
//Solution by Joseph Goodknight
//j@JosephGoodknight.com

// If the numbers 1 to 5 are written out in words: one, two, three, four, five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.

// If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?

// NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and forty-two) contains 23 letters and 115 (one hundred and fifteen) contains 20 letters.
//The use of "and" when writing out numbers is in compliance with British usage.

#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include <cmath>
#include <algorithm>

int maxInteger = 1000;

int letters_one = 3;
int letters_two = 3;
int letters_three = 5;
int letters_four = 4;
int letters_five = 4;
int letters_six = 3;
int letters_seven = 5;
int letters_eight = 5;
int letters_nine = 4;

int zero_digit_letter_counts[10] = {0, letters_one, letters_two, letters_three, letters_four, letters_five, letters_six, letters_seven, letters_eight, letters_nine};

int letters_ten = 3;
int letters_eleven = 6;
int letters_twelve = 6;
int letters_thirteen = 8;
int letters_fourteen = 8;
int letters_fifteen = 7;
int letters_sixteen = 7;
int letters_seventeen = 9;
int letters_eighteen = 8;
int letters_nineteen = 8;

int teen_letter_counts[10] = {letters_ten, letters_eleven, letters_twelve, letters_thirteen, letters_fourteen, letters_fifteen, letters_sixteen, letters_seventeen, letters_eighteen, letters_nineteen};

int letters_twenty = 6;
int letters_thirty = 6;
int letters_forty = 5;
int letters_fifty = 5;
int letters_sixty = 5;
int letters_seventy = 7;
int letters_eighty = 6;
int letters_ninety = 6;
int letters_hundred = 7;

int ten_digit_letter_counts[11] = {0, 0, letters_twenty, letters_thirty, letters_forty, letters_fifty, letters_sixty, letters_seventy, letters_eighty, letters_ninety};

int letters_thousand = 8;

int letters_and = 3;



int totalLetterCount = 0;

int maxOrderOfMagnitude = std::log10((float)maxInteger);

int main()
{

	for(int numberToCount = 1; numberToCount < maxInteger + 1; ++numberToCount) {
		int this_number_count = 0;

		int digit_zero  = numberToCount % 10;
		int digit_one   = (numberToCount / 10) % 10;
		int digit_two = (numberToCount / 100) % 10;
		int digit_three  = (numberToCount / 1000) % 10;

		if(digit_one == 1) { //then the number is considered a teen

			this_number_count = this_number_count + teen_letter_counts[digit_zero];

		} else { //we add the number for the tens place and the ones place

			this_number_count = this_number_count + zero_digit_letter_counts[digit_zero];
			this_number_count = this_number_count + ten_digit_letter_counts[digit_one];

		}

		if(digit_two != 0 && (digit_one != 0 || digit_zero !=0)) {
			this_number_count = this_number_count + letters_and;
		}

		if(digit_two != 0) {
			this_number_count = this_number_count + zero_digit_letter_counts[digit_two] + letters_hundred;

		}

		if(digit_three != 0) {

			this_number_count = this_number_count + zero_digit_letter_counts[digit_three] + letters_thousand;

		}
			std::cout << numberToCount << "-->" <<  this_number_count <<"\n";

		totalLetterCount = totalLetterCount + this_number_count;
	}

	std::cout << "\n" << "ANSWER: " <<  totalLetterCount <<"\n";

	return 0;
}
