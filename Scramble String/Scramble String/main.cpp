//
//  main.cpp
//  Scramble String
//
//  Created by Renchu Song on 10/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>

using namespace::std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
        int n = (int)s1.length(), m = (int)s2.length();
		if (n != m) return false;
		if (n == 0) return true;
		
		bool dp[n][n][m];
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				for (int k = 0; k < m; ++k)
					dp[i][j][k] = false;
		
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j) if (s1[i] == s2[j]) dp[i][i][j] = true;
		
		for (int seg = 1; seg < n; ++seg) {
			for (int i = 0; i + seg < n; ++i) {
				int j = i + seg;
				for (int k = 0; k < i - j + m; ++k) {
					for (int l = 0; l < j - i; ++l) {
						dp[i][j][k] |= dp[i][i + l][j + k - i - l] && dp[i + l + 1][j][k];
						dp[i][j][k] |= dp[i][i + l][k] && dp[i + l + 1][j][k + l + 1];
					}
				}
			}
		}
		return dp[0][n - 1][0];
    }
};

int main(int argc, const char * argv[])
{

	cout << (new Solution())->isScramble("ab", "ab") << endl;
	
	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}

