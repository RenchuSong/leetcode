//
//  main.cpp
//  Subsets
//
//  Created by Renchu Song on 6/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int>> result;
		vector<int> one;
		result.push_back(one);
		sort(S.begin(), S.end());
		for (int i = 0; i < S.size(); ++i) {
			int len = (int)result.size();
			for (int j = 0; j < len; ++j) {
				vector<int> node = result[j];
				node.push_back(S[i]);
				result.push_back(node);
			}
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

