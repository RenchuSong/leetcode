//
//  main.cpp
//  Search for a Range
//
//  Created by Renchu Song on 7/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace  std;

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
		vector<int> result;
		result.push_back(-1);
		result.push_back(-1);
        int l = 0, r = n - 1, m = 0;
		while (l <= r) {
			m = (l + r) / 2;
			if (A[m] == target) break;
			if (A[m] < target) l = m + 1; else r = m - 1;
		}
		if (l > r) return result;
		result[0] = result[1] = m;
		l = 0; r = m - 1;
		while (l <= r) {
			int p = (l + r) / 2;
			if (A[p] == target) result[0] = p;
			if (A[p] >= target) r = p - 1; else l = p + 1;
		}
		l = m + 1; r = n - 1;
		while (l <= r) {
			int p = (l + r) / 2;
			if (A[p] == target) result[1] = p;
			if (A[p] <= target) l = p + 1; else r = p - 1;
		}
		return result;
    }
};

int main(int argc, const char * argv[])
{

	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}

