//
//  main.cpp
//  Sort Colors
//
//  Created by Renchu Song on 5/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>

class Solution {
public:
    void sortColors(int A[], int n) {
        int one = -1, two = -1, three = -1;
		for (int i = 0; i < n; ++i) {
			if (A[i] == 2) {
				A[++three] = A[i];
			} else if (A[i] == 1) {
				++two; ++three;
				A[three] = A[two];
				A[two] = 1;
			} else if (A[i] == 0) {
				++one; ++two; ++three;
				A[three] = A[two];
				A[two] = A[one];
				A[one] = 0;
			}
		}
    }
};

int main(int argc, const char * argv[])
{

	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}

