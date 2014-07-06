//
//  main.cpp
//  Pascal's Triangle
//
//  Created by Renchu Song on 5/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace::std;
class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int>> result;
		if (numRows > 0) {
			vector<int> one;
			one.push_back(1);
			result.push_back(one);
			for (int i = 1; i < numRows; ++i) {
				vector<int> node;
				node.push_back(1);
				for (int j = 1; j < i; ++j) node.push_back(result.back()[j - 1] + result.back()[j]);
				node.push_back(1);
				result.push_back(node);
			}
		}
		return result;
    }
};

int main(int argc, const char * argv[])
{
	vector<vector<int>> result = (new Solution())->generate(1);
	for (int i = 0; i < 1; ++i) {
		for (int j = 0; j <= i; ++j) cout << result[i][j] << " ";
		cout << endl;
	}
    return 0;
}

