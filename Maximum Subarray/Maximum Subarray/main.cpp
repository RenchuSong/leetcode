//
//  main.cpp
//  Maximum Subarray
//
//  Created by Renchu Song on 5/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int maxSubArray(int A[], int n) {
        int result = A[0], mid = A[0];
		for (int i = 1; i < n; ++i) {
			if (mid < 0) mid = A[i]; else mid += A[i];
			if (mid > result) result = mid;
		}
		return result;
    }
	
	int maxSubArrayDivideAndConquer(int A[], int n) {
        return divideSubArr(A, 0, n - 1);
    }
	
	int divideSubArr(int A[], int l, int r) {
		if (l == r) return A[l];
		int m = (l + r) >> 1;
		int leftDiv = divideSubArr(A, l, m);
		int rightDiv = divideSubArr(A, m + 1, r);
		int left = 1 << 31, right = 1 << 31;
		int tmp = 0;
		for (int i = m; i >= l; --i) {
			tmp += A[i];
			if (tmp > left) left = tmp;
		}
		tmp = 0;
		for (int i = m + 1; i <= r; ++i) {
			tmp += A[i];
			if (tmp > right) right = tmp;
		}
		int result = leftDiv > rightDiv ? leftDiv : rightDiv;
		return result > left + right ? result : left + right;
	}
};
int main(int argc, const char * argv[])
{
	int a[9] = {-2,1,-3,4,-1,2,1,-5,4};
	cout << (new Solution())->maxSubArray(a, 9) << endl;
    return 0;
}

