//
//  main.cpp
//  Search Insert Position
//
//  Created by Renchu Song on 4/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        int l = 0, r = n - 1;
		while (l <= r) {
			int m = (l + r) >> 1;
			if (A[m] == target) return m;
			if (A[m] < target) l = m + 1; else r = m - 1;
		}
		return l;
    }
};

int main(int argc, const char * argv[])
{
	int A[5] = {1, 3, 5, 7, 8};
	cout << (new Solution())->searchInsert(A, 5, 5) << endl;
	cout << (new Solution())->searchInsert(A, 5, 2) << endl;
	cout << (new Solution())->searchInsert(A, 5, 7) << endl;
	cout << (new Solution())->searchInsert(A, 5, 6) << endl;
	
    return 0;
}

