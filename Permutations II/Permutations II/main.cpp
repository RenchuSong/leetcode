//
//  main.cpp
//  Permutations II
//
//  Created by Renchu Song on 15/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
	map<int, int> occur, used;
	
	void dfs(vector<vector<int> > &result, vector<int> &item, int d, int n) {
		if (d == n) {
			result.push_back(item);
			return;
		}
		for (pair<int, int> p: occur) {
			if (used[p.first] < p.second) {
				++used[p.first];
				item.push_back(p.first);
				dfs(result, item, d + 1, n);
				item.pop_back();
				--used[p.first];
			}
		}
	}
	
    vector<vector<int> > permuteUnique(vector<int> &num) {
		vector<vector<int> > result;
        int n = (int)num.size();
		for (int i = 0; i < n; ++i) ++occur[num[i]];
		vector<int> item;
		dfs(result, item, 0, n);
		return result;
    }
};

int main(int argc, const char * argv[])
{
	vector<int> n {1, 1};
	vector<vector<int> > result = (new Solution())->permuteUnique(n);
	for (vector<int> item: result) {
		for (int i : item) cout << i << " "; cout << endl;
	}
	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}

