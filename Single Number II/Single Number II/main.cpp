//
//  main.cpp
//  Single Number II
//
//  Created by Renchu Song on 4/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int singleNumberNaive(int A[], int n) {
		int result = 0;
        for (int i = 0; i < 32; ++i) {
			int mask = 1 << i;
			int mid = 0;
			for (int j = 0; j < n; ++j)
				mid += (A[j] & mask) ? 1 : 0;
			result += (mid % 3) > 0 ? mask : 0;
		}
		return result;
    }
	
	int singleNumber(int A[], int n) {
		int ones = 0, twos = 0, threes = 0;
		for (int i = 0; i < n; ++i) {
			twos |= ones & A[i];
			ones ^= A[i];
			threes = ones & twos;
			ones &= ~threes;
			twos &= ~threes;
		}
		return ones;
	}
};

int main(int argc, const char * argv[])
{
	int A[10] = {-2,-2,1,1,-3,1,-3,-3,-4,-2};
	cout << (new Solution())->singleNumber(A, 10) << endl;
    return 0;
}

