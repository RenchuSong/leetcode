//
//  main.cpp
//  Remove Element
//
//  Created by Renchu Song on 5/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int result = 0;
		for (int i = 0; i < n; ++i) {
			if (A[i] != elem) {
				A[result++] = A[i];
			}
		}
		return result;
    }
};

int main(int argc, const char * argv[])
{
	int a[10] = {1, 3, 2, 1, 3, 4, 1, 1, 4, 5};
	cout << (new Solution())->removeElement(a, 10, 1) << endl;
    return 0;
}

