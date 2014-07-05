//
//  main.cpp
//  Remove Duplicates from Sorted Array
//
//  Created by Renchu Song on 5/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>

using namespace::std;

class Solution {
public:
    int removeDuplicates(int A[], int n) {
		if (n == 0) return 0;
        int result = 0;
		for (int i = 1; i < n; ++i) {
			if (A[i] > A[result]) {
				A[++result] = A[i];
			}
		}
		return result + 1;
    }
};

int main(int argc, const char * argv[])
{
	int a[3] = {1, 1, 2};
	int r = (new Solution())->removeDuplicates(a, 1);
	for (int i = 0; i < r; ++i)
		cout << a[i] << endl;
    return 0;
}

