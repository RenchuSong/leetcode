//
//  main.cpp
//  Combination Sum II
//
//  Created by Renchu Song on 8/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<vector<int>> result;
		vector<int> init;
		vector<int> sum;
		result.push_back(init);
		sum.push_back(0);
		sort(num.begin(), num.end());
		for (int i = 0; i < num.size();) {
			int len = (int)result.size();
			int k = i;
			while (k < num.size() - 1 && num[k + 1] == num[k]) ++k;
			for (int l = 1; l <= k - i + 1; ++l)
				for (int j = 0; j < len; ++j) {
					if (sum[j] + num[i]*l <= target) {
						vector<int> mid = result[j];
						for (int p = 0; p < l; ++p)
							mid.push_back(num[i]);
						result.push_back(mid);
						sum.push_back(sum[j] + num[i]*l);
					}
				}
			i = k + 1;
		}
		vector<vector<int>> ret;
		for (int i = 0; i < result.size(); ++i) {
			if (sum[i] == target)
				ret.push_back(result[i]);
		}
		return ret;
    }
};

int main(int argc, const char * argv[])
{
	vector<int> num {2,2,1,4,3};
	vector<vector<int>> result = (new Solution())->combinationSum2(num, 8);
	for (int i = 0; i < result.size(); ++i) {
		for (int j = 0; j < result[i].size(); ++j) cout << result[i][j] << " ";
		cout << endl;
	}
	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}

