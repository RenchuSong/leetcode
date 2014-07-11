//
//  main.cpp
//  Distinct Subsequences
//
//  Created by Renchu Song on 10/7/14.
//  Copyright (c) 2014 Renchu Song. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int numDistinct(string S, string T) {
        int n = (int)S.length(), m = (int)T.length();
		if (n < m || m == 0) return 0;
		int dp[n + 1][m + 1];
		for (int i = 0; i <= n; ++i) for (int j = 0; j <= m; ++j) dp[i][j] = 0;
		for (int i = 0; i <= n; ++i)
			dp[i][0] = 1;
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j) {
				dp[i][j] = dp[i - 1][j];
				if (S[i - 1] == T[j - 1]) dp[i][j] += dp[i - 1][j - 1];
			}
		return dp[n][m];
    }
};

int main(int argc, const char * argv[])
{
	cout << (new Solution())->numDistinct("ccc", "c") << endl;
	// insert code here...
	std::cout << "Hello, World!\n";
    return 0;
}

