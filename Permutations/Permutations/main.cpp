//
//  main.cpp
//  Permutations
//
//  Created by Renchu Song on 6/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
        vector<vector<int>> result;
		result.push_back(num);
		int n = (int)num.size();
		int a[n];
		for (int i = 0; i < n; ++i) a[i] = i;
		while (true) {
			int p = n - 1;
			while ((p > 0 && a[p] < a[p - 1])) --p;
			if (p == 0) break;
			--p;
			int q = n - 1;
			while (a[q] < a[p]) --q;
			a[p] ^= a[q]; a[q] ^= a[p]; a[p] ^= a[q];
			int l = p + 1, r = n - 1, m = (r - l + 1) / 2;
			for (int i = 0; i < m; ++i) {
				a[l + i] ^= a[r - i];
				a[r - i] ^= a[l + i];
				a[l + i] ^= a[r - i];
			}
			vector<int> one;
			for (int i = 0; i < n; ++i) one.push_back(num[a[i]]);
			result.push_back(one);
		}
		return result;
    }
};

int main(int argc, const char * argv[])
{
	vector<int> a;
	a.push_back(1);
	a.push_back(1);
	a.push_back(1);
	a.push_back(1);
	(new Solution())->permute(a);
    return 0;
}

