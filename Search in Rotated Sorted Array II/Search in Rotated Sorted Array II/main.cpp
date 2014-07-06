//
//  main.cpp
//  Search in Rotated Sorted Array II
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
			if (A[m] < last) right = m;
			else if (A[m] > last) left = m + 1;
			else {
				int tmp = last, z = left;
				for (int i = right; i >= z; --i) {
					if (A[i] <= tmp) {
						tmp = A[i];
						left = i;
					}
					if (A[i] > last) break;
				}
				break;
			}
		}
		int l = 0, r = n - 1;
		while (l <= r) {
			int m = (l + r) / 2;
			int mid = A[(m + left) % n];
			if (mid == target) return true;
			if (mid < target) l = m + 1; else r = m - 1;
		}
		return false;
    }
};

int main(int argc, const char * argv[])
{
	int a[5] = {1,3,1,1,1};
	for (int i = 0; i < 5; ++i)
		cout << (new Solution())->search(a, 5, i) << endl;
    return 0;
}
