//
//  main.cpp
//  First Missing Positive
//
//  Created by Renchu Song on 10/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int firstMissingPositive(int A[], int n) {
		for (int i = 0; i < n; ++i) {
			if (A[i] == i + 1) continue;
			if (A[i] <= 0 || A[i] > n) continue;
			int tmp = A[i];
			while (tmp > 0 && tmp <= n) {
				int mid = A[tmp - 1];
				if (mid == tmp) break;
				A[tmp - 1] = tmp;
				tmp = mid;
			}
		}
		for (int i = 0; i < n; ++i) if (A[i] != i + 1) return i + 1;
		return n + 1;
    }
};

int main(int argc, const char * argv[])
{
	int a[4] {-1,-1,-1,-1};
	cout << (new Solution())->firstMissingPositive(a, 3) << endl;
	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}

