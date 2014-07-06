//
//  main.cpp
//  Remove Duplicates from Sorted Array II
//
//  Created by Renchu Song on 6/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int removeDuplicates(int A[], int n) {
        int result = 0;
		for (int i = 1; i < n; ++i) {
			if (A[i] > A[result] || (A[i] == A[result] && (result == 0 || A[result] > A[result - 1]))) {
				A[++result] = A[i];
			}
		}
		return n > 0 ? result + 1 : result;
    }
};

int main(int argc, const char * argv[])
{

	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}

