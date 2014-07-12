//
//  main.cpp
//  Regular Expression Matching
//
//  Created by Renchu Song on 12/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>
#include <cstring>

using namespace::std;

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        int n = (int)strlen(p), m = (int)strlen(s);
		bool dp[n + 1][m + 1];
		memset(dp, false, sizeof(dp));
		dp[0][0] = true;
		for (int i = 1; i <= n; ++i)
			for (int j = 0; j <= m; ++j) {
				char pat = p[i - 1];
				if (pat == '*') {
					dp[i][j] |= dp[i - 2][j];
				}
				if (j > 0) {
					char mac = s[j - 1];
					if (pat == mac) dp[i][j] |= dp[i - 1][j - 1];
					if (pat == '.') dp[i][j] |= dp[i - 1][j - 1];
					if (pat == '*') {
						dp[i][j] |= dp[i - 2][j];
						if (p[i - 2] == mac || p[i - 2] == '.') dp[i][j] |= dp[i - 2][j - 1] | dp[i][j - 1];
					}
				}
			}

		return dp[n][m];
    }
};

int main(int argc, const char * argv[])
{
	cout << (new Solution())->isMatch("aa","a") << endl;
	cout << (new Solution())->isMatch("aa","aa") << endl;
	cout << (new Solution())->isMatch("aaa","aa") << endl;
	cout << (new Solution())->isMatch("aa","a*") << endl;
	cout << (new Solution())->isMatch("aa",".*") << endl;
	cout << (new Solution())->isMatch("ab",".*") << endl;
	cout << (new Solution())->isMatch("aab","c*a*b") << endl;
	cout << (new Solution())->isMatch("aa","c*a*b") << endl;

	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}

