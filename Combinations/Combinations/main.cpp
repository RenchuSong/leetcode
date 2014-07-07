//
//  main.cpp
//  Combinations
//
//  Created by Renchu Song on 6/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int>> result;
		if (k == 0) return result;
		int a[k];
		for (int i = 0; i < k; ++i) a[i] = i + 1;
		vector<int> init;
		for (int i = 1; i <= k; ++i) init.push_back(i);
		result.push_back(init);
		while (true) {
			int i;
			for (i = 0; i < k - 1; ++i)
				if (i < k - 1 && a[i] < a[i + 1] - 1) {
					++a[i];
					for (int j = 0; j < i; ++j) a[j] = j + 1;
					break;
				}
			if (i == k - 1) {
				if (a[k - 1] == n) break;
				++a[k - 1];
				for (int j = 0; j < k - 1; ++j) a[j] = j + 1;
			}
			vector<int> init;
			for (int i = 0; i < k; ++i) init.push_back(a[i]);
			result.push_back(init);
		}
		return result;
    }
};

int main(int argc, const char * argv[])
{
	vector<vector<int>> result = (new Solution())->combine(2, 0);
	for (int i = 0; i < result.size(); ++i) {
		for (int j = 0; j < result[i].size(); ++j) cout << result[i][j] << " ";
		cout << endl;
	}
    return 0;
}

