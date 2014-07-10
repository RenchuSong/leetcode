//
//  main.cpp
//  Palindrome Partitioning II
//
//  Created by Renchu Song on 9/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int minCut(string s) {
        int len = (int)s.length();
		if (len <= 1) {
			return 0;
		}
		// Cal palindrome
		bool** dp = new bool*[len];
		for (int i = 0; i < len; ++i)
			dp[i] = new bool[len];
		for (int i = 0; i < len; ++i)
			for (int j = 0; j < len; ++j) dp[i][j] = (i == j);
		for (int i = 0; i < len - 1; ++i) if (s[i] == s[i + 1]) dp[i][i + 1] = true;
		for (int i = 1; i < len - 1; ++i) {
			for (int j = i + 1; j < len; ++j) {
				int p = 2 * i - j;
				if (p > -1 && dp[p + 1][j - 1] && s[p] == s[j]) dp[p][j] = true;
			}
			for (int j = i + 2; j < len; ++j) {
				int p = 2 * i - j + 1;
				if (p > -1 && dp[p + 1][j - 1] && s[p] == s[j]) dp[p][j] = true;
			}
		}
		
		int ans[len];
		for (int i = 0; i < len; ++i) if (dp[0][i]) ans[i] = 0; else ans[i] = (1 << 30) - 1;
		for (int i = 1; i < len; ++i)
			for (int j = 0; j < i; ++j) if (dp[j + 1][i] && ans[i] > ans[j] + 1) ans[i] = ans[j] + 1;
		return ans[len - 1];
    }
};

int main(int argc, const char * argv[])
{

	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}

