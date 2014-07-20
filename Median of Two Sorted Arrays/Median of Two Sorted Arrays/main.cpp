//
//  main.cpp
//  Median of Two Sorted Arrays
//
//  Created by Renchu Song on 17/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
	int findKth(int A[], int m, int B[], int n, int k) {
		if (n == 0) return A[k - 1];
		if (m == 0) return B[k - 1];
		if (A[m - 1] < B[0]) return k <= m ? A[k - 1] : B[k - m - 1];
		if (B[n - 1] < A[0]) return k <= n ? B[k - 1] : A[k - n - 1];
		int l = k - 1 - min(k - 1, n), r = min(k, m);
		while (l <= r) {
			int i = (l + r) / 2;
			int j = k - 1 - i;
			if (j >= 0 && j < n && (i >= m || A[i] >= B[j]) && (i == 0 || A[i - 1] <= B[j])) return B[j];
			if (i >= 0 && i < m && (j >= n || B[j] >= A[i]) && (j == 0 || B[j - 1] <= A[i])) return A[i];
			if (A[i] < B[j]) l = i + 1; else r = i - 1;
		}
		return -1;
	}
	
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int k = (m + n) / 2;
		if ((m + n) % 2) return findKth(A, m, B, n, k + 1); else
			return (findKth(A, m, B, n, k) + findKth(A, m, B, n, k + 1)) / 2.0;
    }
};

int main(int argc, const char * argv[])
{
	int A[1] {1}, B[1] {1};
	cout << (new Solution())->findMedianSortedArrays(A, 1, B, 1) << endl;
	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}

