//
//  main.cpp
//  Search in Rotated Sorted Array
//
//  Created by Renchu Song on 6/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>

using namespace::std;

class Solution {
public:
    int search(int A[], int n, int target) {
        int last = A[n - 1];
		int left = 0, right = n - 1;
		while (left < right) {
			int m = (left + right) / 2;
			if (A[m] < last) right = m; else left = m + 1;
		}
		int l = 0, r = n - 1;
		while (l <= r) {
			int m = (l + r) / 2;
			int mid = A[(m + left) % n];
			if (mid == target) return (m + left) % n;
			if (mid < target) l = m + 1; else r = m - 1;
		}
		return -1;
    }
};

int main(int argc, const char * argv[])
{
	int a[7] = {0, 1, 2, 4, 5, 6, 7};
	for (int i = 0; i < 10; ++i)
		cout << (new Solution())->search(a, 7, i) << endl;
    return 0;
}

