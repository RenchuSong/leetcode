//
//  main.cpp
//  Generate Parentheses
//
//  Created by Renchu Song on 5/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	void gen(int n, int used, int current, string str, vector<string> & result) {
		if (used == n) {
			result.push_back(str.append(current, ')'));
			return;
		}
		gen(n, used + 1, current + 1, str + '(', result);
		if (current > 0) gen(n, used, current - 1, str + ')', result);
	}
	
    vector<string> generateParenthesis(int n) {
        vector<string> result;
		gen(n, 0, 0, "", result);
		return result;
    }
};

int main(int argc, const char * argv[])
{
	vector<string> result = (new Solution())->generateParenthesis(2);
	for (int i = 0; i < result.size(); ++i) cout << result[i] << endl;
    return 0;
}

