//
//  main.cpp
//  Jump Game
//
//  Created by Renchu Song on 7/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>

class Solution {
public:
    bool canJump(int A[], int n) {
		int last = 0;
		for (int i = 0; i < n; ++i) {
			if (i > last) return false;
			if (i + A[i] > last) last = i + A[i];
		}
		return true;
    }
};

int main(int argc, const char * argv[])
{

	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}

