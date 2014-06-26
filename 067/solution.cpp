//Project Euler
//
//PROBLEM 67
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
// Find the maximum total from top to bottom in triangle.txt (right click and 'Save Link/Target As...'), a 15K text file containing a triangle with one-hundred rows.
//
// NOTE: This is a much more difficult version of Problem 18. It is not possible to try every route to solve this problem, as there are 299 altogether! If you could check one trillion (1012) routes every second it would take over twenty billion years to check them all. There is an efficient algorithm to solve it. ;o)

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

	// printTree(myTree);
	// std::cout << "\n";

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

	// printTree(myTree);

	treeLevelList lastLevel = myTree[myTree.size() - 1];
	int maxPath = *std::max_element(lastLevel.begin(), lastLevel.end());

	clock_t endTime = clock();

	std::cout << "\n" << "ANSWER: " <<  maxPath;
	int clocks_per_ms = CLOCKS_PER_SEC / 1000;
	std::cout << "\n" << "CACLULATED IN: " <<  ((double)endTime - (double)startTime) / (double)clocks_per_ms <<" ms\n";
	return 0;
}
