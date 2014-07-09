//
//  main.cpp
//  Jump Game II
//
//  Created by Renchu Song on 8/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>

class Solution {
public:
    int jump(int A[], int n) {
        if (n < 2) return 0;
        int r1 = A[0], r2 = A[0], ans = 1;
        for (int i = 1; i < n; ++i) {
            if (i > r1) {
                r1 = r2;
                ++ans;
            }
            if (i + A[i] > r2) r2 = i + A[i];
        }
        return ans;
    }
};

int main(int argc, const char * argv[])
{

	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}

