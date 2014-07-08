//
//  main.cpp
//  Combination Sum
//
//  Created by Renchu Song on 7/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int>>  helper(vector<int> &cand, int curIndex, int left) {
		vector<vector<int>> result;
		if (cand[curIndex] == left) {
			vector<int> one;
			one.push_back(left);
			result.push_back(one);
			return result;
		}
		if (curIndex < cand.size() - 1) {
			vector<vector<int>> tmp = helper(cand, curIndex + 1, left);
			for (int i = 0; i < tmp.size(); ++i) result.push_back(tmp[i]);
		}
		if (cand[curIndex] <= left / 2) {
			vector<vector<int>> tmp = helper(cand, curIndex, left - cand[curIndex]);
			for (int i = 0; i < tmp.size(); ++i) {
				tmp[i].push_back(cand[curIndex]);
				result.push_back(tmp[i]);
			}
		}
		return result;
	}
	
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
		unique(candidates.begin(), candidates.end());
		vector<vector<int>> result;
		if (candidates.size() > 0) {
			result = helper(candidates, 0, target);
			for (int i = 0; i < result.size(); ++i)
				reverse(result[i].begin(), result[i].end());
		}
		return result;
    }
};

int main(int argc, const char * argv[])
{
	vector<int> cand;
	cand.push_back(2);
	cand.push_back(3);
	cand.push_back(6);
	cand.push_back(7);
	
	vector<vector<int>> result = (new Solution())->combinationSum(cand, 13);
	for (int i = 0; i < result.size(); ++i) {
		for (int j = 0; j < result[i].size(); ++j) cout << result[i][j] << " "; cout << endl;
	}
    return 0;
}

