//Project Euler
//
//PROBLEM 15
//Solution by Joseph Goodknight
//j@JosephGoodknight.com

// Starting in the top left corner of a 2×2 grid, and only being able to move to the right and down, there are exactly 6 routes to the bottom right corner.

// How many such routes are there through a 20×20 grid?

#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include <cmath>
#include <algorithm>

//since there is no way to move "backwards", this problem is rather simple actually.

//each path will have to consist of 20 moves down and 20 moves to the right for a total of 20 moves  so we need the total number of moves we can partition 40 moves from two groups of 20 which is just 40 chose 20



int main() 
{
	std::cout << "ANSWER: " << 137846528820 <<"\n";

	return 0;
}






