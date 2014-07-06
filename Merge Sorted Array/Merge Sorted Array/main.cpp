//
//  main.cpp
//  Merge Sorted Array
//
//  Created by Renchu Song on 5/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        int one = m - 1, two = n - 1;
		for (int i = m + n - 1; i >= 0; --i) {
			if (one == -1) A[i] = B[two--];
			else if (two == -1) A[i] = A[one--];
			else if (A[one] > B[two]) A[i] = A[one--];
			else A[i] = B[two--];
		}
    }
};

int main(int argc, const char * argv[])
{
	int a[10] = {1, 3, 5, 7, 9};
	int b[4] = {4, 6, 8, 9};
	(new Solution())->merge(a, 5, b, 4);
	for (int i = 0; i < 9; ++i) cout << a[i] << " "; cout << endl;
    return 0;
}

