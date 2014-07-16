//
//  main.cpp
//  Next Permutation
//
//  Created by Renchu Song on 15/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int n = (int) num.size();
		if (n < 2) return;
		int p = n - 1;
		while (p > 0 && num[p - 1] >= num[p]) --p;
		if (p == 0) {
			reverse(num.begin(), num.end());
			return;
		}
		--p;
		int q = n - 1;
		while (num[q] <= num[p]) --q;
		swap(num[p], num[q]);
		++p; q = n - 1;
		while (p < q) {
			swap(num[p], num[q]);
			++p; --q;
		}
    }
};

int main(int argc, const char * argv[])
{
	vector<int> a {1, 3, 3, 3};
	(new Solution())->nextPermutation(a);
	for (int i : a) cout << i << endl;
	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}

