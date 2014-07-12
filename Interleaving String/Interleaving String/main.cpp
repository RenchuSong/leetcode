//
//  main.cpp
//  Interleaving String
//
//  Created by Renchu Song on 11/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>
#include <cstdlib>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = (int)s1.length(), m = (int)s2.length();
		if (s3.length() != n + m) return false;
		int dp[n + 1][m + 1];
		memset(dp, false, sizeof(dp));
		dp[0][0] = true;
		for (int i = 0; i <= n; ++i)
			for (int j = 0; j <= m; ++j) {
				if (i > 0 && dp[i - 1][j] && s3[i + j - 1] == s1[i - 1]) dp[i][j] = true;
				if (j > 0 && dp[i][j - 1] && s3[i + j - 1] == s2[j - 1]) dp[i][j] = true;
			}
		return dp[n][m];
    }
};

int main(int argc, const char * argv[])
{
	cout << (new Solution())->isInterleave("aabcc", "x", "xaabcc") << endl;
	cout << (new Solution())->isInterleave("aabcc", "dbbca", "aadbbbaccc") << endl;
	
	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}

