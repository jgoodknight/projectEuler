//Project Euler
//
//PROBLEM 18
//Solution by Joseph Goodknight
//j@JosephGoodknight.com

// By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.
//
// 3
// 7 4
// 2 4 6
// 8 5 9 3
//
// That is, 3 + 7 + 4 + 9 = 23.
//
// Find the maximum total from top to bottom of the triangle below:
//
// 75
// 95 64
// 17 47 82
// 18 35 87 10
// 20 04 82 47 65
// 19 01 23 75 03 34
// 88 02 77 73 07 63 67
// 99 65 04 28 06 16 70 92
// 41 41 26 56 83 40 80 70 33
// 41 48 72 33 47 32 37 16 94 29
// 53 71 44 65 25 43 91 52 97 51 14
// 70 11 33 28 77 73 17 78 39 68 17 57
// 91 71 52 38 17 14 91 43 58 50 27 29 48
// 63 66 04 68 89 53 67 30 73 16 69 87 40 31
// 04 62 98 27 23 09 70 98 73 93 38 53 60 04 23
//
// NOTE: As there are only 16384 routes, it is possible to solve this problem
//by trying every route. However, Problem 67, is the same challenge with a
//triangle containing one-hundred rows; it cannot be solved by brute force, and
//requires a clever method! ;o)

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <time.h>

int max(int &one, int &two) {
	if(one > two) {
		return one;
	} else {
		return two;
	}
}

template<typename treeType>
void printTree(treeType &toBePrinted) {
	for(auto level : toBePrinted) {
		for(auto i : level) {
			std::cout << i << " ";
		}
		std::cout << "\n";
	}
}

int main()
{
	clock_t startTime = clock();

	typedef std::vector<int> treeLevelList;
	typedef std::vector<treeLevelList> dumbTree;

	dumbTree myTree;

	std::fstream treeFile("tree.txt");
	// std::fstream treeFile("test_tree.txt");
	std::string treeLevel;

	int currentInteger;

	while(std::getline(treeFile, treeLevel)) {
		treeLevelList thisLevel;

		std::istringstream iss(treeLevel);

		while(iss >> currentInteger) {
			thisLevel.push_back(currentInteger);
		}
		myTree.push_back(thisLevel);
	}

	printTree(myTree);
	std::cout << "\n";

	//starting on the second level of the tree, we will look at the previous
	//levels and add the maximum possible amount from the two possibilities
	//repeating until we get to the last level
	int possibleAddition1, possibleAddition2, maxNodeIndex;
	for(int treeLevelIndex = 1; treeLevelIndex < myTree.size(); ++treeLevelIndex) {

		maxNodeIndex = myTree[treeLevelIndex].size();

		possibleAddition1 = 0;
		possibleAddition2 = 0;

		//go through every node and check the two (or one) nodes above it
		for(int nodeIndex = 0; nodeIndex < maxNodeIndex; ++nodeIndex) {
			if(nodeIndex < maxNodeIndex - 1) {
				possibleAddition1 = myTree[treeLevelIndex - 1][nodeIndex];
			}
			if(nodeIndex > 0) {
				possibleAddition2 = myTree[treeLevelIndex - 1][nodeIndex - 1];
			}
			myTree[treeLevelIndex][nodeIndex] = myTree[treeLevelIndex][nodeIndex] + max(possibleAddition1, possibleAddition2);
		}

	}

	printTree(myTree);

	treeLevelList lastLevel = myTree[myTree.size() - 1];
	int maxPath = *std::max_element(lastLevel.begin(), lastLevel.end());

	clock_t endTime = clock();

	std::cout << "\n" << "ANSWER: " <<  maxPath;
	int clocks_per_ms = CLOCKS_PER_SEC / 1000;
	std::cout << "\n" << "CACLULATED IN: " <<  ((double)endTime - (double)startTime) / (double)clocks_per_ms <<" ms\n";
	return 0;
}
