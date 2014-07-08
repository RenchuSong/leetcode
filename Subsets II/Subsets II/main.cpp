//
//  main.cpp
//  Subsets II
//
//  Created by Renchu Song on 7/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	void helper(vector<vector<int>> & result, int obj, int c) {
		int len = (int)result.size();
		for (int i = 0; i < len; ++i) {
			for (int j = 1; j <= c; ++j) {
				vector<int> tmp = result[i];
				for (int k = 0; k < j; ++k) tmp.push_back(obj);
				result.push_back(tmp);
			}
		}
	}
	
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        sort(S.begin(), S.end());
		vector<vector<int>> result;
		vector<int> none;
		result.push_back(none);
		int obj = S[0], c = 1;
		for (int i = 1; i < S.size(); ++i) {
			if (S[i] > obj) {
				helper(result, obj, c);
				c = 1;
				obj = S[i];
			} else ++c;
		}
		helper(result, obj, c);
		return result;
    }
};

int main(int argc, const char * argv[])
{
	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}

